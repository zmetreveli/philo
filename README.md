# 🧠 Philosophers (42 Project)

**A multithreaded simulation of the classic Dining Philosophers Problem**
Project developed at [42 Barcelona](https://42barcelona.com), focused on concurrency, mutex handling and race condition avoidance.

---

## 📚 Table of Contents

* [Introduction](#introduction)
* [Rules of the Problem](#rules-of-the-problem)
* [Goals of the Project](#goals-of-the-project)
* [Program Architecture](#program-architecture)
* [How to Use](#how-to-use)
* [Implementation Details](#implementation-details)
* [Error Handling](#error-handling)
* [Bonus](#bonus)
* [What I Learned](#what-i-learned)
* [Resources](#resources)

---

## 🧩 Introduction

> "The challenge is not just writing threads. It's avoiding chaos."
> — Me, after debugging segfault at 3 AM

This project simulates the behavior of several philosophers who alternate between thinking, eating, and sleeping. The difficulty? They must **share forks** (mutexes) and avoid starvation or deadlock.

---

## 🍝 Rules of the Problem

1. Philosophers sit around a table.
2. Each has a fork to their left and right.
3. To eat, a philosopher must pick up **both** forks.
4. Philosophers alternate between:

   * Thinking 🧠
   * Eating 🍽️
   * Sleeping 🛌
5. If a philosopher doesn't eat in `time_to_die`, they die 💀

---

## 🎯 Goals of the Project

* Learn about **pthread**, **mutex**, **race conditions**, and **deadlocks**
* Master handling **timing**, **shared memory**, and **safe concurrency**
* Ensure no philosopher dies unless it’s meant to by the simulation
* Implement both mandatory and **bonus** versions with semaphores and processes

---

## 🏐 Program Architecture

```
philo/
├── Makefile
├── includes/
│   ├── check_args.h
│   ├── colors.h
│   ├── get_time.h
│   ├── handle_meal.h
│   ├── init.h
│   ├── philo.h
│   ├── routine.h
│   ├── structs.h
│   └── waiter.h
├── src/
│   ├── check_args.c
│   ├── get_time.c
│   ├── handle_meal.c
│   ├── init.c
│   ├── main.c
│   ├── routine.c
│   ├── utils.c
│   └── waiter.c

philo_bonus/
├── includes/           # Bonus-specific headers
│   └── ...
├── src/                # Bonus-specific source files
│   └── ...
├── main.c              # Bonus entry point
├── Makefile
```

---

## 🔧 How to Use

```bash
make
./philo number_of_philos time_to_die time_to_eat time_to_sleep [num_times_each_philo_must_eat]
```

Example:

```bash
./philo 5 800 200 200
```

This runs 5 philosophers with:

* 800ms before dying
* 200ms to eat
* 200ms to sleep

Optional 5th argument: stop when all philosophers have eaten N times.

---

## 🧠 Implementation Details

### 🧵 Threads & Mutexes (Mandatory)

* Each philosopher is a **pthread**.
* Each fork is a **mutex**.
* Shared data is protected by **mutexes** (`write_lock`, `dead_lock`, `meal_lock`).

### ☠️ Death Monitor

* A separate thread watches over the philosophers.
* If a philosopher doesn’t eat in time, it prints death and stops.

### ⏱️ Custom Sleep

```c
int ft_usleep(size_t milliseconds)
```

Standard `usleep` isn’t accurate across platforms, so a custom function ensures precision.

### 🛡️ Race Condition Protection

* Critical sections are wrapped in `pthread_mutex_lock/unlock`.
* Fork acquisition is ordered to avoid **deadlocks**.

---

## ❓ Error Handling

* Detects invalid inputs.
* Limits philosophers to ≤ 200 (recommended).
* All `malloc`/`pthread_create` calls are checked.
* All mutexes and semaphores are cleaned up properly.

---

## ✨ Bonus

* ✅ **Process-based implementation** with `fork()`
* ✅ Rewritten using **semaphores** (`sem_open`, `sem_wait`, `sem_post`)
* ✅ Output synchronization via `write_sem`
* ✅ Separate death detection mechanism per process
* ✅ Works with edge cases: 1 philosopher, rapid starvation, etc.

Run:

```bash
make bonus
./philo_bonus 5 800 200 200
```

---

## 💡 What I Learned

* How to manage shared memory using **threads** and **processes**
* Difference between **mutexes** and **semaphores**
* Safe synchronization patterns
* Debugging race conditions and deadlocks
* Advanced use of `pthread`, `sem_open`, `fork`, and signal handling

---

## 📂 Resources

* [42 Project PDF](https://cdn.intra.42.fr/pdf/pdf/135363/en.subject.pdf)
* [CodeVault Threads in C](https://www.youtube.com/playlist?list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY)
* [What is a mutex? (YouTube)](https://www.youtube.com/watch?v=oq29KUy29iQ)
* [Race Conditions Explained](https://www.youtube.com/watch?v=FY9livorrJI)
