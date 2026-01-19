#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Verifier.h"
#include <iostream>
#include <map>

using namespace llvm;

static std::unique_ptr<LLVMContext> TheContext;
static std::unique_ptr<Module> TheModule;
static std::unique_ptr<IRBuilder<>> Builder;

void InitializeModule() {
  TheContext = std::make_unique<LLVMContext>();
  TheModule = std::make_unique<Module>("AMD_Compiler_Demo", *TheContext);
  Builder = std::make_unique<IRBuilder<>>(*TheContext);
}

int main() {
  InitializeModule();

  // Create a function: double test(double x, double y)
  std::vector<Type*> Doubles(2, Type::getDoubleTy(*TheContext));
  FunctionType *FT = FunctionType::get(Type::getDoubleTy(*TheContext), Doubles, false);
  Function *F = Function::Create(FT, Function::ExternalLinkage, "test", TheModule.get());

  // Create basic block "entry"
  BasicBlock *BB = BasicBlock::Create(*TheContext, "entry", F);
  Builder->SetInsertPoint(BB);

  // Simple math: return x + y
  Value *LHS = F->arg_begin();
  Value *RHS = F->arg_begin() + 1;
  Value *Result = Builder->CreateFAdd(LHS, RHS, "addtmp");
  Builder->CreateRet(Result);

  // Verify and print the LLVM IR
  verifyFunction(*F);
  TheModule->print(errs(), nullptr);

  return 0;
}