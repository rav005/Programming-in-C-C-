#pragma once
#define MAX 3

 namespace w1{

	 class CString{
			char words[MAX+1];
		public:
			CString();
			CString(const char*);
			void disply(std::ostream& os) const;		
	};
	std::ostream& operator<<(std::ostream& os, const CString& obj);
 };
