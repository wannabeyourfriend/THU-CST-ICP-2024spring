# include <stdio.h>
# include <stdlib.h>

struct Node
{
	int data;
	struct Node* next; 
};

struct Node* insertatend(struct Node* head,int n)//在链表的尾部插入一个新节点
{
	struct Node*temp,*p;//定义两个指针
	temp  =(struct Node*)malloc(sizeof(struct Node));//为新节点分配内存,并将temp指向新节点,即temp是新节点,
	temp->data = n;
	temp->next = NULL;
	p = head;//创建一个指针指向头节点

	while(p->next!=NULL){
		p = p->next;
	}//遍历链表,直到p指向链表的最后一个节点
	p->next = temp;//将新节点插入到链表的尾部,即p的下一个节点是temp,而temp的下一个节点是NULL,即temp是链表的最后一个节点,所以temp->next = NULL

	return head;//返回头指针,即头节点,因为头指针是不变的,所以返回头指针即可
}

void traverse(struct Node* head)//遍历链表,逆序打印链表中的数据
{
	if(head==NULL)
		return;
	printf("%d ",head->data);//打印当前节点的数据,即head->data
	traverse(head->next);//递归调用
}

void BubbleSort(struct Node* head)
{
	struct Node* ptr = NULL;
	struct Node* lptr = NULL;//定义两个指针,ptr和lptr,ptr指向头节点,lptr指向NULL
	struct Node* temp = NULL;
	int swapped;//定义一个变量swapped,用来标记是否发生了交换

	if(head==NULL){
		return;
	}//如果链表为空,则直接返回

		
		temp = head;
		do{
			swapped = 0;
			ptr = head;
			while( ptr->next != lptr){
			if((ptr->data) > (ptr->next->data))
			{
				swap(ptr,ptr->next);
				swapped = 1;
			}
			ptr = ptr->next;
			} 
			temp = temp ->next;
		}while (temp->next != NULL);
	//如果ptr->data > ptr->next->data,则交换两个节点的数据,并将swapped置为1,
	//表示发生了交换,然后将ptr指向下一个节点,直到ptr->next = lptr,即ptr指向lptr,此时退出循环
	//利用两层while循环，进行冒泡排序，保证每次外侧循环都能找到最大的元素放到最后

}

void swap(struct Node* a, struct Node* b)
{
	struct Node * temp;
	temp = a->data;
	a->data = b->data;
	b->data = temp;
}//交换两个节点的数据

struct Node* insertatbeg(struct Node* head,int n)
{
	struct Node* temp;

	temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = n;
	temp->next = head;
	head = temp;

	return head;
}//在链表的头部插入一个新节点

int main()
{
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	struct Node* head = NULL;
	head = insertatbeg(head, a);
	head = insertatend(head, b);
	head = insertatend(head, c);

	BubbleSort(head);

	traverse(head);
	return 0;
}