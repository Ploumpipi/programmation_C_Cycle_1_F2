#ifndef DEFINE_H_INCLUDED
#define DEFINE_H_INCLUDED

extern void initmotsecret (char motsecret [];);
extern void cachemotsecret (char tabmodif [];);
extern void saisilettre (char *lettre);
extern int checklettre (char lettre, char motsecret[], char tabmodif[]);

#endif // DEFINE_H_INCLUDED
