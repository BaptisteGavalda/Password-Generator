# Password-Generator
Little project of password generator in C lang.

## Installation
Generate binary with
```
make
```
Install it with
```
make install
```

## Execution
The programm take at least 2 parametters, the application or website name and a secret password. It will display the generated password with it. You can add some options to match your needs. You can choose the length of your password and choose wich characters will be contain in it.
```
passgen name pass_phrase [length] [OPTION]
--no-digit
--no-letter
--noupercase
--no-sepcials-characters
```

## Future Improvements
I want to improve :
* how the password is generated
* how the parameters are taken
* how the memory is used
