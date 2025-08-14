# SafePass
SafePass is a lightweight password generator written in C++ and uses Qt framework for the User-Interface.

---
## Features
- Generator capable of building passwords using Upper-case, Lower-case, Numbers and Symbols, with a maximum length of 256 characters.
- Simple and user-friendly UI.
- Password strength checker tool.
- Copy to clipboard button.

---
## The Generation
The generator is built using the random library and relies on a secure seeding system.

---
## The password strength checker
has four levels of strength (based on entropy):
- Weak (28 bits or less).
- Medium (between 35 and 28 bits).
- Strong (between 59 and 35 bits).
- Very Strong (60 bits or more).

---
