//To validate EAN no according to EAN rules.
bool isValid(const char* str);

//Forward decleration for isRegistered function.
struct Prefix;

//This will extract area, publisher and title from EAN no.
int isRegistered(const Prefix* p, const char* str, char area[], char publisher[], char title[]);



