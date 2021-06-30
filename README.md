# Engima

This program is an emulation of the popular German cryptography machine, Enigma. The Enigma machine was a cipher device developed and used in the early to mid-20th century to protect commercial, diplomatic, and military communication. It was employed extensively by Nazi Germany during World War II, in all branches of the German military. It had a very sophisticated and unique mechanism for the era it was developed in and was almost unbreachable, until Alan Turing, built the Turing machine to break its code.

The speciality of its algorithm lies in the fact that, first, it is impossible to know how a message would be coded even if someone knew the key used, and secondly, encryption and decryption used the same logic and key, which meant even if someone intercepted the message, it would be of no use, until the key is known as well.

This program, coded in C++, catched the essence of the logic, that was used to encrypt/decrypt in the Enigma machines, with minor tweaks. And implements the same in a file-handling methodology, providing functionality to read and write, the codes/messages directly from a text file.

More on enigma: https://www.theguardian.com/technology/2014/nov/14/how-did-enigma-machine-work-imitation-game
