#ifndef ADV
#define ADV

#include <iostream>
#include <fstream>
#include <istream>
#include <sstream>
#include <string>
#include <vector>
#include "AdvObject.h"
#include "AdvRoom.h"

using namespace std;

class Adventure
{

public:
	// No other public functions are needed.
	Adventure();
	Adventure(string objfile, string rmfile, string cmdfile);
	void Play();
	
private:
	// Loading functions
	void LoadObjects(string filename);
	void LoadRooms(string filename);
	void LoadSynonyms(string filename);

	// You should will need additional commands
	// other than the quit, help, and move commands.
	// Some of the commands should take arguments.
	// For some it may be helpful to return values.
	// You should only make functions for built-in commands.
	// For example, you should NOT make one for WAVE.
	void GetUserCmd(string &verb, string &obj);
	void QuitCmd();
	void HelpCmd();
	int MotionCmd(string motionName);


	// You will need some attributes to keep
	// track what room the player is currently in
	// and what objects are currently being held.

	// You should have some methods to help you 
	// print the room and objects.

	// You will also need attributes to store 
	// objects and rooms.
	
	struct Synonym {
		string word;
		string synonym;
	};
	vector<Synonym> synonyms;
	string GetSynonym(string str);
};

// A little helper fuction that converts a string to uppercase.
static void ConvertToUpper(string &s) {
	for (int i = 0; i < s.length(); i++)
		s[i] = toupper(s[i]);
}

#endif