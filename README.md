# Kaleidoscope-LLVM IR Generator

This project demonstrates the programmatic generation of **LLVM Intermediate Representation (IR)** using the LLVM C++ API. 

## Technical Highlights
* **LLVM IRBuilder**: Utilized to construct functions and basic blocks.
* **Instruction Emission**: Generates optimized `fadd` instructions in SSA (Static Single Assignment) form.
* **Verification**: Uses `llvm::verifyFunction` to ensure IR structural integrity.

## Why this matters for AMD
Understanding IR generation is critical for targeting hardware-specific backends. This project shows my ability to bridge high-level logic with the LLVM ecosystem used by the AMD GPU-Compilers team.
