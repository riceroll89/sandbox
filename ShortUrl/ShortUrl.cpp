#include <cstdio>
#include <iostream>
#include <string>
#include <map>
using namespace std;

static const char alphaNum[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

char randomCharGen() {
	return alphaNum[rand() % (sizeof(alphaNum) - 1)];
}

string encode(string longUrl) {
	int keyLength = 6;
	string randomKey;
	for (int i = 0; i < keyLength; i++) {
		randomKey += randomCharGen();
	}
	string shortUrl = "www.shorturl.com/" + randomKey;
	return shortUrl;
}


int main() {
	string longUrl = "https://github.com/jasonh9/codeetuts/tree/master/Leetcode_Questions/Encode_and_Decode_TinyURL";
	std::map<std::string, std::string> keyMap;
	keyMap[encode(longUrl)] = longUrl;
	for (std::map<std::string, std::string>::iterator i = keyMap.begin(); i != keyMap.end(); i++) {
		cout << i->first << " => " << i->second << endl;
	}
	//for (string i = keyMap.begin(); i != keyMap.end(); i++)



	return 0;
}