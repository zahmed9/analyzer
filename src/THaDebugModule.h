#ifndef ROOT_THaDebugModule
#define ROOT_THaDebugModule

//////////////////////////////////////////////////////////////////////////
//
// THaDebugModule
//
//////////////////////////////////////////////////////////////////////////

#include "THaPhysicsModule.h"
#include "THaPrintOption.h"
#include <vector>

class THaVar;
class THaCut;

class THaDebugModule : public THaPhysicsModule {
  
public:
  THaDebugModule( const char* var_list, const char* test="" );
  virtual ~THaDebugModule();
  
  virtual EStatus   Init( const TDatime& run_time );
  virtual void      Print( Option_t* opt="" ) const;
  virtual Int_t     Process( const THaEvData& evdata );

protected:

  enum EFlags { 
    kStop  = BIT(0),    // Wait for key press after every event
    kCount = BIT(1),    // Run for fCount events   
    kQuiet = BIT(2)     // Run quietly (don't print variables)
  };

  std::vector<const THaVar*> fVars; // Array of pointers to variables 
  THaPrintOption  fVarString; // Set of strings with variable names
  Int_t           fFlags;     // Option flags
  Int_t           fCount;     // Event counter
  TString         fTestName;  // Name of test to evaluate before printing
  THaCut*         fTest;      // Pointer to test object to evaulate

private:

  void PrintEvNum( const THaEvData& ) const;

  THaDebugModule();
  THaDebugModule( const THaDebugModule& );
  THaDebugModule& operator=( const THaDebugModule& );

  ClassDef(THaDebugModule,0)  // Physics module for debugging
};

#endif
