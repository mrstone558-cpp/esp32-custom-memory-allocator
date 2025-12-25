# esp32-custom-memory-allocator

## About the Project
An experimental free-list based memory allocator for ESP32,
demonstrating heap reuse and manual memory management on top of the
ESP32 safe heap.

## Why I Built This
I built this project to deeply understand how memory is managed at a
low level, how `malloc` and `free` work internally, and what kinds of
mistakes and risks are involved in manual memory management.

## What I Learned
- How memory is managed internally
- How `malloc` and `free` work
- Free-list based allocation
- Pointer unlinking in linked lists
- Heap reuse vs fresh allocation
- Why memory allocators are powerful but dangerous

## Conclusion
Dynamic memory allocation is extremely powerful, but also risky if not
handled carefully. One of the best ways to truly understand memory
allocators is to build a simple one yourself. This project is a learning
experiment, not a production allocator, but it was highly educational.

## Thanks