#ifndef stack_arr
#define stack_arr
struct s{
    int boyut;
    int tepe;
    int *dizi;
};
typedef s stack;
stack *tanim(stack *s);
int pop(stack *);
void push(int,stack *);
void bastir(stack *);
#endif