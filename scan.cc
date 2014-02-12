/* this program is a directory scanner, that recursively lists directories
 *
 * the program accepts a number of options:
 * -a: show all files (essentially shows hidden files that start with '.')
 * -f: show plain files
 * -d: show directories
 * -p pattern: show files/dirs that match pattern
 *  	this is a glob wildcard, NOT a regular expression
 *  	matches only the last component of a path
 * -D days: show files/dirs modified 'days' days ago
 *  	items modified today are 0 days ago
 *  	items modified any time yesterday are modified 1 day ago... etc
 */




#define _SVID_SOURCE  //this is required for portability of scandir() and alphasort

#include <time.h> //this is to convert the file system call time using localtime()
#include <iostream>
#include <string>
#include <vector>
#include <sys/stat.h> // for the cals to stat(2) for the filesystem access --gives everything
#include <cstring>  //this is for strcmp() which is to suppress '.' and '..' in scandir()
#include <unistd.h>  //this is to use the getopt() command line parsing function
#include <glob.h> //this is, clearly, to be able to use glob()...check the man files, please
#include <dirent.h> //this is to be able to use scandir()


using namespace std;

int p = 0, a = 0;
char *pattern = NULL;
vector<string> totalFiles;
vector<string> patternFiles;




void getFiles(const char *folder, char * pattern, vector<string> &fileList)
{
	chdir(folder);

	glob_t buffer; //creates the glob object that stores the results of globbing

	glob( pattern,GLOB_TILDE, NULL, &buffer); //this actually globs

	string path;
	for (unsigned long i=0; i < buffer.gl_pathc; ++i){
		struct stat stat_buf;
/*		path += folder;
		path += '/';*/
		path += buffer.gl_pathv[i];

		stat(path.c_str(), &stat_buf);
		
		if (S_ISDIR (stat_buf.st_mode)) {
			path.clear();
			path += folder;
			path += '/';
			path += buffer.gl_pathv[i];
			if (a == 0){
				if (buffer.gl_pathv[i][0] == '.'){}
				else{
					fileList.push_back(path + "/");
					getFiles(buffer.gl_pathv[i], pattern, patternFiles);
				}
			}
			else {
				fileList.push_back(path + "/");	
				getFiles(buffer.gl_pathv[i], pattern, patternFiles);
			}
		}
		else {	
			path.clear();
			path += folder;
			path += '/';
			path += buffer.gl_pathv[i];
			if (a == 0){	
				if (buffer.gl_pathv[i][0] == '.'){}
				else{
					fileList.push_back(path);
				}
			}
			else {
				fileList.push_back(path);	
			}
		}
		path.clear();
	}
	//free the buffer structure for future globbing
	if (buffer.gl_pathc > 0 )
		globfree( &buffer);
}




void showFiles( vector<string> &fileList)
{
	for (unsigned long i=0; i < fileList.size(); i++)
		cout <<  fileList[i] << endl;
}






void scanAll(const char *folder)
{
	struct dirent **nameList;
	int n;
	n = scandir(folder, &nameList, NULL, alphasort);
	
	
	if (n < 0)
		perror("scandir: Directory not Found or Directory not given.\n");
	else 
	{
		string path;
		
		while (n--) {
			if ((strcmp(nameList[n]->d_name,".") == 0) || (strcmp(nameList[n]->d_name, "..") == 0))
			{
				free(nameList[n]);
			}
			else{
			
				struct stat stat_buf;
				path += folder;
				path += "/";
				path += nameList[n]->d_name;

				stat(path.c_str(), &stat_buf);

				if (S_ISDIR (stat_buf.st_mode)) {
					if ( a ==0){
						if ( (nameList[n]->d_name)[0] == '.') {}
						else{
							totalFiles.push_back(path + "/");
							scanAll(path.c_str());
						}
					}
					else{
						totalFiles.push_back(path + "/");	
						scanAll(path.c_str());
					}
				}
				else {
					if ( a==0){
						if ( (nameList[n]->d_name)[0] == '.') {}
						else{
							totalFiles.push_back(path);
						}
					}
					else{
						totalFiles.push_back(path);	
					}
				}

				path.clear();
				free(nameList[n]);
			}
		}
		free(nameList);
	}
}


int diff(const char nowTime[], const char fileTime[])
{
	int difference = 0;

	string now(nowTime);
	string file(fileTime);

	string nowYear = now.substr(0,4);
	string nowDay = now.substr(4,3);
	string fileYear = file.substr(0,4);
	string fileDay = file.substr(4,3);

	int yearNow = atoi(nowYear.c_str());
	int yearFile = atoi(fileYear.c_str());

	int dayNow = atoi(nowDay.c_str());
	int dayFile = atoi(fileDay.c_str());

	if (yearNow != yearFile){
		difference = 365.25 * (yearNow - yearFile);
		difference += dayNow;
		difference += (365 - dayFile);
	}
	else{
		difference += (dayNow - dayFile);
	}

	return difference;
}




int main (int argc, char **argv)
{
	int opt, days;
	int  f = 0, d = 0, D = 0;

	//get the time now and put it into nowTime
	time_t rawtime;
	struct tm *timeinfo;
	char nowTime[8];
	time (&rawtime);
	timeinfo = localtime(&rawtime);
	strftime(nowTime, 8, "%Y%j", timeinfo);

	if (argc == 1){
		cerr << "Hey dummy... you didn't give any directory\n";
		exit(1);
	}

	int count = 0;

	// this while loop sets dummy variables for each commandline argument given
	while ((opt = getopt(argc, argv, "afdp:D:")) != -1) {
		switch (opt) {
			case 'a':
				a = 1;
				count += 1;
				break;
			case 'f':
				f = 1;
				count += 1;
				break;
			case 'd':
				d = 1;
				count += 1;
				break;
			case 'p':{
				p = 1;
				pattern = optarg;
				count += 2;
				break;
			}
			case 'D':{
				D = 1;
				days = atoi(optarg);
				count += 2;
				break;
			}
			default:		
				cerr << argv[0] << ": an invalid command line argument was given" << endl;
				return 1;
		}
	}


	vector<char *> dir_given;
	for ( int i = (count + 1); i < argc ; i++)
		dir_given.push_back(argv[i]);

	for (unsigned long i = 0; i < dir_given.size(); i++){	
		totalFiles.push_back(string(dir_given[i])+"/");
		scanAll(dir_given[i]);	
	}






	if ( p == 1 ) {
		//this packs patternFiles with all of the files found by glob
		for (unsigned long i = 0 ; i < dir_given.size() ; i++){
			patternFiles.push_back(string(dir_given[i])+"/");
			getFiles(dir_given[i], pattern, patternFiles);
		}
		
		//now we start to pass them through the gauntlet
		if ( f == 1 && d == 0){
			int n = patternFiles.size();
			while(n--){
				struct stat stat_buf;
				stat(patternFiles[n].c_str(), &stat_buf);
		
				if (S_ISDIR (stat_buf.st_mode)){
					patternFiles.erase(patternFiles.begin()+n);	
				}
			}
		}
			
		if ( d == 1 && f == 0) {	
			int n = patternFiles.size();
			while(n--){
				struct stat stat_buf;
				stat(patternFiles[n].c_str(), &stat_buf);
		
				if (S_ISREG (stat_buf.st_mode)){
					patternFiles.erase(patternFiles.begin()+n);	
				}
			}
		}
	

		if (D == 1){		
			int n = patternFiles.size();
			while(n--){
				struct stat stat_buf;
				stat(patternFiles[n].c_str(), &stat_buf);
				char fileTime[8];
				//gets the time and puts it in fileTime as a cstring
				strftime(fileTime, 8, "%Y%j", localtime(&stat_buf.st_mtime));
				
				int difference = diff(nowTime, fileTime);
				if (difference != days)
					patternFiles.erase(patternFiles.begin()+n);
			}
		}
		
		if ( a == 0){
			int n = patternFiles.size();
			while(n--){
				if ( patternFiles[n].c_str()[0] == '.')
					patternFiles.erase(patternFiles.begin()+n);
			}
		}

		showFiles(patternFiles);
	}
/*	
	char *folder = argv[argc-1]; // folder is directory given at command line to traverse
	
	totalFiles.push_back(string(folder)+"/");
*/	
	
	vector<string> finalFiles;
	
/*	
	scanAll(folder); 
*/

	//traverses and places all file paths into totalFiles
	//Now we start to erase from the master list totalFiles those that 
	//dont correspond to the command line arguments


	//if no arguments given, then print everything traversed
	if ( a==0 && f==0 && d==0 && D==0 && p==0){
		for (unsigned long i=0; i < totalFiles.size(); i++)
			cout << totalFiles[i] << endl;
		return 0;
	}









	if ( p == 0 ) {

		if ( f == 1 && d == 0){
			int n = totalFiles.size();
			while(n--){
				struct stat stat_buf;
				stat(totalFiles[n].c_str(), &stat_buf);
		
				if (S_ISDIR (stat_buf.st_mode)){
					totalFiles.erase(totalFiles.begin()+n);	
				}
			}
		}
			
		if ( d == 1 && f == 0) {	
			int n = totalFiles.size();
			while(n--){
				struct stat stat_buf;
				stat(totalFiles[n].c_str(), &stat_buf);
		
				if (S_ISREG (stat_buf.st_mode)){
					totalFiles.erase(totalFiles.begin()+n);	
				}
			}
		}
	

		if (D == 1){		
			int n = totalFiles.size();
			while(n--){
				struct stat stat_buf;
				stat(totalFiles[n].c_str(), &stat_buf);
				char fileTime[8];
				//gets the time and puts it in fileTime as a cstring
				strftime(fileTime, 8, "%Y%j", localtime(&stat_buf.st_mtime));
				
				int difference = diff(nowTime, fileTime);
				if (difference != days)
					totalFiles.erase(totalFiles.begin()+n);
			}
		}	
		
		if ( a == 0){
			int n = totalFiles.size();
			while(n--){
				if ( *(totalFiles[n].c_str()) == '.')
					totalFiles.erase(totalFiles.begin()+n);
			}
		}
		showFiles(totalFiles);
	}

	//Now we print out everything that made it
/*	
	for (unsigned long i=0; i < totalFiles.size() ; i++)
		cout << totalFiles[i] << endl;
*/
	return 0;
}
