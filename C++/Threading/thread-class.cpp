#include <iostream>
#include <vector>
#include <thread>
#include <sstream>
#include <string>

// A rope is made up of many threads.  Each thread is a strand of the rope.

template<class T>
class Strand 
{
  std::thread  t;
  T            value;
  bool         active;
public:
  Strand() : active(false)
    { std::cout << "Strand() ctor\n"; }
 ~Strand()            
    { std::cout << "~Strand() dtor: value=" << value << '\n'; }
  void Set(T v)   
    { value=v; }
  void Print() 
    { std::stringstream ss; ss << "Strand::Print "   << value << "\n"; std::cout << ss.str(); }
  void Compute() 
    { std::stringstream ss; ss << "Strand::Compute " << value << "\n"; std::cout << ss.str(); }
  void ComputeArg(T arg) 
    { std::stringstream ss; ss << "Strand::ComputeArg " << arg   << "\n"; std::cout << ss.str(); }
  void Run()         
    { if(!active) {t = std::thread( std::bind(&Strand::Compute,    &*this) );  active = true;} }
  void Run(T arg)  
    { if(!active) {t = std::thread( std::bind(&Strand::ComputeArg, &*this, arg) ); active = true;} }
  void Wait()        
    { if(active)  {t.join(); active = false;} }
  bool Busy()        
    { return active; }
};

int main()
{
   const int                STRANDS_PER_ROPE = 4;
   Strand<char>             rope[STRANDS_PER_ROPE];

   int                      arg;
   std::string              argString;

   argString="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
   arg   = 0;
   for(auto& strand : rope) strand.Set(argString[arg++]);
   
   std::cout << "\nRun():\n";
   for(auto& strand : rope) strand.Run();
   for(auto& strand : rope) if(strand.Busy()) strand.Wait();

   std::cout << "\nRun(arg--):\n";
   arg   = argString.size() - 1;
   for(auto& strand : rope) strand.Run(argString[arg--]);
   for(auto& strand : rope) if(strand.Busy()) strand.Wait();

   std::cout << "\nRun() + Run(arg++):\n";
   argString="abcdefghijklmnopqrstuvwxyz";
   arg   = 0;
   for(auto& strand : rope) {if(arg&1) strand.Run(argString[arg]); else strand.Run(); arg++;}
   for(auto& strand : rope) if(strand.Busy()) strand.Wait();

   std::cout << "\nmain exiting\n";
}
