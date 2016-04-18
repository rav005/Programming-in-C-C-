 // Workshop 10 - Multi-Threading
 // SecureData.cpp

 #include <iostream>
 #include <fstream>
 #include <string>
 #include <thread>
 #include <future>
 #include <memory>
 #include "SecureData.h"

 namespace w10 {

     void converter(char* t, char key, int n, const Cryptor& c) {
		 for (int i = 0; i < n; i++){
             t[i] = c(t[i], key);
		 }
     }

     SecureData::SecureData(const char* file, char key) {
         // open text file
         std::fstream input(file, std::ios::in);
         if (!input)
             throw std::string("\n***Failed to open file ") +
              std::string(file) + std::string(" ***\n");

         // copy from file into memory
         nbytes = 0;
         input >> std::noskipws;
         while (input.good()) {
             char c;
             input >> c;
             nbytes++;
         }
         nbytes--;
         input.clear();
         input.seekg(0, std::ios::beg);
         text  = new char[nbytes + 1];

         int i = 0;
         while (input.good())
             input >> text[i++];
         text[--i] = '\0';
         std::cout << "\n" << nbytes << " bytes copied from text "
          << file << " into memory (null byte added)\n";
         encoded = false;

         // encode using key
         code(key);
         std::cout << "Data encrypted in memory\n";
     }

     SecureData::~SecureData() {
         delete [] text;
     }

     void SecureData::display(std::ostream& os) const {
         if (text && !encoded)
             os << text << std::endl;
         else if (encoded)
             throw std::string("\n***Data is encoded***\n");
         else
             throw std::string("\n***No data stored***\n");
     }

     void SecureData::code(char key) {
		 auto cores = std::thread::hardware_concurrency();
		 int workUnit = nbytes / cores;
		 std::unique_ptr<std::thread[]> t(new std::thread[cores]);

		 for(int core = 0; core <= cores; core++) {
			int b = core * workUnit;
            int e = b    + workUnit;
            if ( core == cores-1 ){
				e = nbytes;
			}
            auto f = std::bind(converter, text+b, key, e-b, Cryptor());
            std::cout << "starting thread\n";
            t[core] = std::thread( f );
         }
         for(int core = 0; core < cores; core++){
             t[core].join();
		 }
         encoded = !encoded;
     }

     void SecureData::backup(const char* file) {
         if (!text)
             throw std::string("\n***No data stored***\n");
         else if (!encoded)
             throw std::string("\n***Data is not encoded***\n");
         else {
             // open binary file
			 std::ofstream outfile(file, std::ios::binary);
             // write binary file here
			 if(outfile.is_open()){
				outfile.write(text, nbytes);
			 }else{
				throw std::string("\n***Unable to open") + (*file) + ("***\n");
			 }
         }
     }

     void SecureData::restore(const char* file, char key) {
         if(text != nullptr){
			 delete [] text;
			 text = nullptr;
		 }
		 // open binary file
		 std::ifstream infile(file, std::ios::binary);
		 
		 if(infile.is_open()){
			 // allocate memory here
			 nbytes = 0;
			 infile >> std::noskipws;
			 while (infile.good()) {
				 char c;
				 infile >> c;
				 nbytes++;
			 }
			 nbytes--;
			 infile.clear();
			 infile.seekg(0, std::ios::beg);
			 text  = new char[nbytes + 1];
 
			 // read binary file here
			 int i = 0;
			 while (infile.good()){
				 infile >> text[i++];
			 }
			 text[--i] = '\0';
		 }else{
			throw std::string("\n***Unable to open ") + (*file) + ("***\n");
		 }

         std::cout << "\n" << nbytes + 1 << " bytes copied from binary file " 
          << file << " into memory (null byte included)\n";
         encoded = true;

         // decode using key
         code(key);
         std::cout << "Data decrypted in memory\n\n";
     }

     std::ostream& operator<<(std::ostream& os, const SecureData& sd) {
         sd.display(os);
         return os;
     }

 }