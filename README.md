# 👋 Hi, I'm Qianqian | OpenMP Learning Journey 🚀
![C++](https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![OpenMP](https://img.shields.io/badge/OpenMP-FF9900?style=for-the-badge&logo=openmp&logoColor=white)
![Git](https://img.shields.io/badge/Git-F05032?style=for-the-badge&logo=git&logoColor=white)

### 📖 My OpenMP Learning Log
I am currently documenting my progress as I dive deep into **Parallel Computing** and **HPC**. My goal is to master multi-core optimization on macOS.

---

### 📝 Study Progress Tracker
- [x] **Basics**: Fork-Join model & Parallel Regions
- [x] **Work-sharing**: Mastered `#pragma omp for` vs `parallel`
- [x] **Data Scoping**: Understanding `shared`, `private`, and the importance of `default(none)`
- [x] **Synchronization**: Implementing thread-safe calculations with `reduction`
- [ ] **Advanced**: Array sections in reductions & performance profiling

---

### 💻 Current Lab Environment
- **Hardware**: MacBook Air (10 Threads)
- **Compiler**: Clang with OpenMP support
- **IDE**: VS Code with Git integration

---

### 🛠 My Parallel Code Snippet
> "Always use `default(none)` to avoid hidden bugs!"

```cpp
#pragma omp parallel default(none) \
                   shared(data, n) \
                   private(id)
{
    int id = omp_get_thread_num();
    // Processing parallel tasks...
}
