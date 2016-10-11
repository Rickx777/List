#include <stdio.h>
#include <stdlib.h>

struct node{ int i; struct node *next; };

void print_list(struct node*);
struct node* insert_front(struct node*, int);
struct node* free_list(struct node*);

void print_list(struct node* h){
  printf("[HEAD]");
  while (h){
    printf("-(%d)-", h-> i);
    h = h -> next;
  }
  printf("[TAIL]\n");
}

struct node* insert_front(struct node* h, int d){
  struct node* in = (struct node*) malloc(sizeof(struct node));
  in->i = d;
  in->next = h;
  return in;
}

struct node* free_list(struct node* h){
  struct node* ret = h;
  struct node* t = h;
  while(t){
  t = h->next;
  free(h);
  h = t;
  }
  return ret;
}

int main(){
    struct node *c = (struct node*) malloc(sizeof(struct node));
    struct node *w = (struct node*) malloc(sizeof(struct node));
    c->i = 2;
    c->next = w;
    w->i = 1;
    print_list(c);
    c = insert_front(c, 3);
    print_list(c);
    c = free_list(c);
    print_list(c);
  	return 0;
}
