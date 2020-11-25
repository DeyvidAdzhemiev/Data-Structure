#ifndef _EXPRESSIONS_H
#define _EXPRESSIONS_H

int apply(char op, int left, int right);
int priority(char c);
bool isOperator(char c);

#endif