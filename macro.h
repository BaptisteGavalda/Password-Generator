#ifndef MACRO_H_
# define MACRO_H_

#define IS_ALPHA(x) (((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z')) ? (1) : (0))
#define IS_LOWERCASE(x) ((x >= 'a' && x <= 'z') ? (1) : (0))
#define ISNUM(x) ((x >= '0' && x <= '9') ? (1) : (0))
#define IS_SPECIAL(x) (((x >= '!' && x <= '/') || (x >= ':' && x <= '@') || (x >= '[' && x <= '`') || (x >= '{' && w <= '~')) ? (1) : (0))

#endif /* MACRO_H_ */
