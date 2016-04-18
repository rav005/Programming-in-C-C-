#pragma once

enum PassType {Student, Adult};

namespace w2{

	class Station{
		std::string name;
		unsigned int student;
		unsigned int adult;
	
		public:
			Station();
			void set(const std::string&, unsigned stud, unsigned adu);
			void update(PassType, int); //NEED to know how to use this to set the values...
			const std::string& getName() const;	
			unsigned inStock(PassType) const;

	};	

	class Stations{
		int total;
		Station* locations;
		char* filename;
		PassType passes[2];
		public:
			Stations(char *f_name);
			~Stations();
			void update() const;
			void restock() const;
			void report() const;
	};
}