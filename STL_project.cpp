/**********************                                                            
Standard template library (STL_project)      
			   
1: singly linear linked list
	(functionalities)		
2: Singly circular linked kist
	(functionalities)		
3: Doubly linear linked list
	(functionalities)		
4: Doubly circular linked list
	(functionalities)	
	
5: stack
6: Queue
7: Bubble sort 
**********************/

#include<iostream>
using namespace std;

/**********************
	Singly_Linear
***********************/

template <class T>
struct node 					
{
	T Data;
	struct node *Next;
	//self referencing pointer
};

template <class T>
class SinglyLL //class declaration for singly linear linklist.
{
	private:
	struct node<T>*Head;
	int iSize;
	
	public:
	SinglyLL(); //constructor
	~SinglyLL(); //Destructor
	void InsertFirst(T);
	void InsertLast(T);
	void InsertAtPos(T,int);
	void DeleteFirst();
	void DeleteLast();
	void DeleteAtPos(int);
	int Count();
	void Display();
	bool SearchElement(T);
	int Frequency(T);
	T summation();
	int FirstOccurance(T);
	T Maximum();
	T Minimum();
};

template<class T>
SinglyLL<T>::SinglyLL() 
//constructor
{
	Head=NULL;
	iSize=0;
}
template<class T>  
SinglyLL<T>::~SinglyLL()
//Destructor
{
	struct node<T> *temp=Head;
	while(Head!=NULL)
	{
		temp=Head;
		Head=Head->Next;
		delete(temp);
	}
}
/*****************************
	Function Name : Count();
	Description  :	Count function is use to count 
					the number of element present 
					in the linkedlist.
					
*****************************/
template <class T>
int SinglyLL<T>::Count()
{
	return iSize;
}

/*****************************
	Function Name : Display();
	Description : Function to Display contains of the linked list

******************************/
template <class T>
void SinglyLL<T>::Display()
{
	struct node<T> *temp=Head;
	while(temp!=NULL)
	{
		cout<<temp->Data<<"\t";
		temp=temp->Next;
	}
	cout<<"\n";
}
/****************************
	Function Name : InsertFirst(T);
	Description : To insert the element at the first position
	: create new node
	: If Head is null then put new node address into Head
	: else Head is not null then firstly Next pointer of new node 
	hold the current Head value and then Head = new node.
	: size veriable increment by one. 
 	
*****************************/
template<class T>
void SinglyLL<T>::InsertFirst(T iNo)
{
	struct node<T> *Newn=NULL;
	Newn=new struct node<T>;
	Newn->Data=iNo;
	Newn->Next=NULL;
	if(Head==NULL)
	{
		Head=Newn;
	}
	else
	{
		Newn->Next=Head;
		Head=Newn;
	}
	iSize++;
}

/**************************
	Function Name : InsertLast(T);
	Descreption : Function to insert last element in linked list
	: create new node of structure node
	: create temporary pointer as temp that hold current value of Head.
	: If Head is null then put new node address into Head
	: else travel the linked list upto temp->Next == null
	then put the address of new node into temp->Next
	: increase size by one.
	
**************************/
template<class T>
void SinglyLL<T>::InsertLast(T iNo )
{
	struct node<T>*Newn=NULL;
	Newn=new struct node<T>;
	Newn->Data=iNo;
	Newn->Next=NULL;
	if(Head==NULL)
	{
		Head=Newn;
	}
	else
	{
		struct node<T>*temp=Head;
		while(temp->Next!=NULL)
		{
			temp=temp->Next;
		}
		temp->Next=Newn;
	}
	iSize++;
}

/**********************
	Function Name : InsertAtPos(T,int);
	Description : Function to insert node at given position in linked list
	: create temp pointor that hold current Head value
	: create new node of structure node
	: If position is not valid then return
	: If position = 1 then call InsertFirst(T) function internally
	: else If position is last position then call InsertLast(T) internally
	: else position is in between then travel the linked list upto that position
	  then Next pointer of new node holds the value of temp->Next (Next pointer of temp)
	  temp->Next = address of new node
	: size (count) increase by one
	
***********************/
template<class T>
void SinglyLL<T>::InsertAtPos(T iNo,int iPos)
{
	struct node <T>*temp=Head;
	struct node<T>*Newn=NULL;
	Newn=new struct node<T>;
	Newn->Data=iNo;
	Newn->Next=NULL;
	if((iPos<1)||(iPos>iSize+1))
	{
		cout<<"Please enter valid position\n";
		return;
	}
	if(iPos==1)   // If insert at 1st position then internally call InsertFirst() 
	{
		InsertFirst(iNo);
	}
	else if(iPos==iSize+1)  // If insert at last position then internally call InsertLast()
	{
		InsertLast(iNo);
	}
	else   
	{
		for(int i=1;i<iPos-1;i++)
		{
			temp=temp->Next;
		}
		Newn->Next=temp->Next;
		temp->Next=Newn;
		iSize++;
	}	
}

/**********************
	Function Name : DeleteFirst();
	Function to delete node at first position in linked list
	: If Head contain null then return
	: else if Head->Next is null then delete Head
	: else create temporary pointer holds the value of Head
	then Head=Head->Next (Head points toword next node)
	and then delete temp
	: Decrease size(count ) by one.
	
***********************/
template<class T>
void SinglyLL<T>::DeleteFirst()
{
	if(Head==NULL) 
	// if Linked list is Empty
	{
		return;
	}
	else if(Head->Next==NULL) 
	// If linked list contain single node
	{
		delete(Head);
		Head=NULL;
	}
	else		
	// If linked list contain more the one element/node.				
	{
		struct node<T>*temp=Head;
		Head=Head->Next;
		delete(temp);
	}
	iSize--;
	
}

/************************
	Function Name : DeleteLast();
	Description : Function to delete last node in the linked list.
	: If Head contain null then return
	: else if Head->Next is null then delete Head
	: else create temporary pointer to travel the linked list (temp = Head)
	travel upto last but one element 
	delete last node (temp->Next)
	: decrease size(count) by one
	
*************************/
template<class T>
void SinglyLL<T>::DeleteLast()
{
	if(Head==NULL)    
	// If linked list is empty 
	{
		return ;
	}
	else if(Head->Next==NULL) 
	//If linked list contain single node
	{
		delete(Head);
		Head=NULL;
	}
	else   
	// If linked list contain more than one node
	{
		struct node<T> *temp=Head;
		while(temp->Next->Next!=NULL)
		{
			temp=temp->Next;
		}
		delete(temp->Next);
		temp->Next=NULL;
	}
	iSize--;
}

/********************************
 Function Name : DeleteAtPos(int);
 Function to delete node at given position in the linked list
 	: create temp pointor that hold current Head value
	: If position is not valid then return
	: If position = 1 then call DeleteFirst(T) function internally
	: else If position is last position then call DeleteLast(T) internally
	: else position is in between then travel the linked list upto that position
	  create target ponter to hold that value (temp->Next)	
	  temp is pointed to next of next node (temp->Next = temp->Next->Next)
	  delete target (node)	
	: size (count) increase by one

**********************************/
template<class T>
void SinglyLL<T>::DeleteAtPos(int iPos)
{
	struct node<T>*temp=Head;    
	// temperory pointer (temp)
	struct node <T> * target=NULL;
	if((iPos<1)||(iPos>iSize))
	{
		return;
	}
	if(iPos==1)
	{
		DeleteFirst();
	}
	else if(iPos==iSize)
	{
		DeleteLast();
	}
	else
	{
		for(int i=1;i<iPos-1;i++)
		{
			temp=temp->Next;
		}
		target=temp->Next;
		temp->Next=temp->Next->Next;
		delete(target);
		iSize--;
	}
}

/************************
	Function Name : SearchElement(T)
	Description : Function for to search any element in the linked
	
*************************/
template <class T>
bool SinglyLL<T>::SearchElement(T iNo)      
//bool is a boolean data type
{
	int i=0,iCnt=0;
	struct node<T>*temp=Head;
	for(i=1;i<=iSize;i++)
	{
		if(temp->Data==iNo)
		{
			iCnt++;
			break;
		}
		temp=temp->Next;
	}
	if(iCnt>0)
	{
		return true;
	}
	else
	{
		return false;
	}

}

/* 
*************************
	Function Name : Frequency(T)
	Description : Function to calculate the frequency 
				  of the particular element
 
**************************/
template <class T>
int SinglyLL<T>::Frequency(T iNo)
{
	int iCnt=0;
	struct node <T> *temp=Head;
	for (int i=1;i<=iSize;i++)
	{
		if(temp->Data==iNo)
		{
			iCnt++;
		}
		temp=temp->Next;
	}
	return iCnt;
}

/*********************
	Function name : summation()
	Description : Function to calculate the summation 
				  of all the element.
	
*********************/
template <class T>
T SinglyLL<T>::summation()
{
	T Sum=0;
	struct node <T> *temp=Head;
	while(temp!=NULL)
	{
		Sum=Sum+(temp->Data);
		temp=temp->Next;
	}
	return Sum;
}

/***********************
	Function Name : FirstOccurance(T);
	Description : Function to find first occurance 
				  index of the particuler element.
				  
************************/
template<class T>
int SinglyLL<T>::FirstOccurance(T iNo)
{
	int i=0;
	struct node <T> *temp=Head;
	for(i=1;i<=iSize;i++)
	{
		if((temp->Data)==iNo)
		{
			break;
		}
		temp=temp->Next;
	}
	return i;
}

//
	//Function name : Maximum();
	//Description : Function to return the maximum value 
		//		  element from the linked list

template<class T>
T SinglyLL<T>::Maximum()
{
	struct node<T>*temp=Head;
	T Max=temp->Data;
	while(temp!=NULL)
	{
		if((temp->Data)>Max)
		{
			Max=temp->Data;
		}
		temp=temp->Next;
	}
	return Max;
}

//***********************
	//Function name : Minimum();
	//Description : Function to return the minimum value element
	//		      from the linked list
//*************************/
template<class T>
T SinglyLL<T>::Minimum()
{
	struct node<T>*temp=Head;
	T Min=temp->Data;
	while(temp!=NULL)
	{
		if((temp->Data)<Min)
		{
			Min=temp->Data;
		}
		temp=temp->Next;
	}
	return Min;
}
/***************************************************
Singly Circular linked list 
Singly Circular linked list using generic programming
*****************************************************/			
//template <class T>    
//Template header
/*struct node 					
{
	T Data;
	struct node *Next;
};
*/

template <class T>
class SinglyCL    
//class declaration for singly Circular linklist.
{
	private:
	struct node<T>*Head;
	struct node<T>*Teil;
	int iSize;
	
	public:
	SinglyCL(); 
	//constructor
	~SinglyCL(); 
	//Destructor
	void InsertFirst(T);
	void InsertLast(T);
	void InsertAtPos(T,int);
	void DeleteFirst();
	void DeleteLast();
	void DeleteAtPos(int);
	int Count();
	void Display();
	bool SearchElement(T);
	int Frequency(T);
	T summation();
	int FirstOccurance(T);
	T Maximum();
	T Minimum();
};


template<class T>
SinglyCL<T>::SinglyCL() 
//constructor
{
	Head=NULL;
	Teil=NULL;
	iSize=0;
}

template<class T>  
SinglyCL<T>::~SinglyCL()
//Destructor
{
	struct node<T> *temp=Head;
	for(int i=1;i<=iSize;i++)
	{
		temp=Head;
		Head=Head->Next;
		delete(temp);
	}
}

/*********************************
	Function Name : Count();
	Description : Count function is use to count the number of 
				  element present in the linkedlist.
				  
**********************************/
template <class T>
int SinglyCL<T>::Count()
{
	return iSize;
}

/***********************
	Function Name : Display();
	Description : Function to Display contains of the linked list
	
************************/
template <class T>
void SinglyCL<T>::Display()
{
	struct node<T> *temp=Head;
	for(int i=1;i<=iSize;i++)
	{
		cout<<temp->Data<<"\t";
		temp=temp->Next;
	}
	cout<<"\n";
}

/************************
	Function Name : InsertFirst(T);
	Description : To insert the element at the first position
				  in the linked list 

************************/
template<class T>
void SinglyCL<T>::InsertFirst(T iNo)
{
	struct node<T> *Newn=NULL;
	Newn=new struct node<T>;
	Newn->Data=iNo;
	Newn->Next=NULL;
	if(Head==NULL)
	{
		Head=Newn;
		Teil=Newn;
		Teil->Next=Head;
	}
	else
	{
		Newn->Next=Head;
		Head=Newn;
		Teil->Next=Head;
	}
	iSize++;
}

/************************
	Function Name : InsertLast(T);
	Description : Function to insert last element in linked list
	
***********************/
template<class T>
void SinglyCL<T>::InsertLast(T iNo )
{
	struct node<T>*Newn=NULL;
	Newn=new struct node<T>;
	Newn->Data=iNo;
	Newn->Next=NULL;
	if(Head==NULL)
	{
		Head=Newn;
		Teil=Newn;
	}
	else
	{
		Teil->Next=Newn;
		Teil=Newn;
		Teil->Next=Head;
	}
	iSize++;
}

/**********************
	Function Name : InsertAtPos(T,int);
	Function to insert node at given position in linked list

**********************/
template<class T>
void SinglyCL<T>::InsertAtPos(T iNo,int iPos)
{
	struct node <T>*temp=Head;
	struct node<T>*Newn=NULL;
	Newn=new struct node<T>;
	Newn->Data=iNo;
	Newn->Next=NULL;
	if((iPos<1)||(iPos>iSize+1))
	{
		cout<<"Please enter valid position\n";
		return;
	}
	if(iPos==1)   
	// If insert at 1st position then internally call InsertFirst() 
	{
		InsertFirst(iNo);
	}
	else if(iPos==iSize+1)  
	// If insert at last position then internally call InsertLast()
	{
		InsertLast(iNo);
	}
	else   
	{
		for(int i=1;i<iPos-1;i++)
		{
			temp=temp->Next;
		}
		Newn->Next=temp->Next;
		temp->Next=Newn;
		iSize++;
	}	
}

/*
	Function Name : DeleteFirst();
	Function to delete node at first position in linked list
*/
template<class T>
void SinglyCL<T>::DeleteFirst()
{
	if(Head==NULL)  
	// if Linked list is Empty
	{
		return;
	}
	else if(Head->Next==NULL) 
	// If linked list contain single node
	{
		delete(Head);
		Head=NULL;
		Teil=NULL;
	}
	else		
	// If linked list contain more the one element/node.				
	{
		struct node<T>*temp=Head;
		Head=Head->Next;
		delete(temp);
		Teil->Next=Head;
	}
	iSize--;
}

/*
	Function Name : DeleteLast();
	Function to delete last node in the linked list.
*/
template<class T>
void SinglyCL<T>::DeleteLast()
{
	if(Head==NULL)    
	// If linked list is empty 
	{
		return ;
	}
	else if(Head->Next==NULL)  
	//If linked list contain single node
	{
		delete(Head);
		Head=NULL;
		Teil=NULL;
	}
	else   
	// If linked list contain more than one node
	{
		struct node <T> *temp=Head;
		for(int i=1;i<iSize-1;i++)
		{
			temp=temp->Next;
		}
		delete(temp->Next);
		temp->Next=Head;
	}
	iSize--;
}

/*
	Function Name : DeleteAtPos(int);
	Function to delete node at given position in the linked list
*/
template<class T>
void SinglyCL<T>::DeleteAtPos(int iPos)
{
	struct node<T>*temp=Head;    
	struct node <T> * target=NULL;
	if((iPos<1)||(iPos>iSize))
	{
		return;
	}
	if(iPos==1)
	{
		DeleteFirst();
	}
	else if(iPos==iSize)
	{
		DeleteLast();
	}
	else
	{
		for(int i=1;i<iPos-1;i++)
		{
			temp=temp->Next;
		}
		target=temp->Next;
		temp->Next=temp->Next->Next;
		delete(target);
		iSize--;
	}
}

/*
	Function Name : SearchElement(T)
	Function for to search any element in the linked
*/
template <class T>
bool SinglyCL<T>::SearchElement(T iNo)      
{
	int i=0,iCnt=0;
	struct node<T>*temp=Head;
	for(i=1;i<=iSize;i++)
	{
		if(temp->Data==iNo)
		{
			iCnt++;
			break;
		}
		temp=temp->Next;
	}
	if(iCnt>0)
	{
		return true;
	}
	else
	{
		return false;
	}

}

/*
	Function Name : Frequency(T)
	Function to calculate the frequency of the particular element
*/
template <class T>
int SinglyCL<T>::Frequency(T iNo)
{
	int iCnt=0;
	struct node <T> *temp=Head;
	for (int i=1;i<=iSize;i++)
	{
		if(temp->Data==iNo)
		{
			iCnt++;
		}
		temp=temp->Next;
	}
	return iCnt;
}

/*
	Function name : summation()
	Function to calculate the summation of all the element.
*/
template <class T>
T SinglyCL<T>::summation()
{
	T Sum=0;
	struct node <T> *temp=Head;
	for(int i=1;i<=iSize;i++)
	{
		Sum=Sum+(temp->Data);
		temp=temp->Next;
	}
	return Sum;
}

/*
	Function Name : FirstOccurance(T);
	Function to find first occurance index of the particuler element.
*/
template<class T>
int SinglyCL<T>::FirstOccurance(T iNo)
{
	int i=0;
	struct node <T> *temp=Head;
	for(i=1;i<=iSize;i++)
	{
		if((temp->Data)==iNo)
		{
			break;
		}
		temp=temp->Next;
	}
	return i;
}

/*
	Function name : Maximum();
	Function to return the maximum value element from the linked list
*/
template<class T>
T SinglyCL<T>::Maximum()
{
	struct node<T>*temp=Head;
	T Max=temp->Data;
	for(int i=1;i<=iSize;i++)
	{
		if((temp->Data)>Max)
		{
			Max=temp->Data;
		}
		temp=temp->Next;
	}
	return Max;
}

/*
	Function name : Minimum();
	Function to return the minimum value element from the linked list
*/
template<class T>
T SinglyCL<T>::Minimum()
{
	struct node<T>*temp=Head;
	T Min=temp->Data;
	for(int i=1;i<=iSize;i++)
	{
		if((temp->Data)<Min)
		{
			Min=temp->Data;
		}
		temp=temp->Next;
	}
	return Min;
}
/************* DOUBLY LINEAR LINKED LIST **********************
   	Subject : Doubly linear linked list using generic programming	
*/

template <class T>      //Template header
struct d_node				
{
	T Data;
	struct d_node *Next;
	struct d_node *prev;
};

template <class T>
class DoublyLL     //class declaration for Doubly linear linklist.
{
	private:
	struct d_node<T>*Head;
	int iSize;
	
	public:
	DoublyLL (); //constructor
	~DoublyLL (); //Destructor
	void InsertFirst(T);
	void InsertLast(T);
	void InsertAtPos(T,int);
	void DeleteFirst();
	void DeleteLast();
	void DeleteAtPos(int);
	int Count();
	void Display();
	bool SearchElement(T);
	int Frequency(T);
	T summation();
	int FirstOccurance(T);
	T Maximum();
	T Minimum();
};

/*
	constrictor (constructor is use to allocate the resourses)
*/
template<class T>
DoublyLL <T>::DoublyLL () //constructor
{
	Head=NULL;
	iSize=0;
}

/*
	destructor  (destructor is use to deallocate the resourses)
*/
template<class T> //Destructor 
DoublyLL<T>::~DoublyLL()
{
	struct d_node<T> *temp=Head;
	for(int i=1;i<=iSize;i++)
	{
		temp=Head;
		Head=Head->Next;
		delete(temp);
	}
}

/*
	Function Name : Count();
	Count function is use to count the number of element present in the linkedlist.
*/
template <class T>
int DoublyLL<T>::Count()
{
	return iSize;
}

/*
	Function Name : Display();
	Function to Display contains of the linked list
*/
template <class T>
void DoublyLL<T>::Display()
{
	struct d_node<T> *temp=Head;
	while(temp!=NULL)
	{
		cout<<temp->Data<<"\t";
		temp=temp->Next;
	}
	cout<<"\n";
}

/*
	Function Name : InsertFirst(T);
	To insert the element at the first position
*/
template<class T>
void DoublyLL<T>::InsertFirst(T iNo)
{
	struct d_node<T> *Newn=NULL;
	Newn=new struct d_node<T>;
	Newn->Data=iNo;
	Newn->Next=NULL;
	Newn->prev=NULL;
	if(Head==NULL)
	{
		Head=Newn;
	}
	else
	{
		Newn->Next=Head;
		Head->prev=Newn;
		Head=Newn;
	}
	iSize++;
}

/*
	Function Name : InsertLast(T);
	Function to insert last element in linked list
*/
template<class T>
void DoublyLL<T>::InsertLast(T iNo )
{
	struct d_node<T>*Newn=NULL;
	Newn=new struct d_node<T>;
	Newn->Data=iNo;
	Newn->Next=NULL;
	Newn->prev=NULL;
	if(Head==NULL)
	{
		Head=Newn;
	}
	else
	{
		struct d_node<T>*temp=Head;
		while(temp->Next!=NULL)
		{
			temp=temp->Next;
		}
		temp->Next=Newn;
		Newn->prev=temp;
	}
	iSize++;
}

/*
	Function Name : InsertAtPos(T,int);
	Function to insert node at given position in linked list
*/
template<class T>
void DoublyLL<T>::InsertAtPos(T iNo,int iPos)
{
	struct d_node <T>*temp=Head;
	struct d_node<T>*Newn=NULL;
	Newn=new struct d_node<T>;
	Newn->Data=iNo;
	Newn->Next=NULL;
	Newn->prev=NULL;
	if((iPos<1)||(iPos>iSize+1))
	{
		cout<<"Please enter valid position\n";
		return;
	}
	if(iPos==1)// If insert at 1st position then internally call InsertFirst() 
	{
		InsertFirst(iNo);
	}
	else if(iPos==iSize+1)// If insert at last position then internally call InsertLast()
	{
		InsertLast(iNo);
	}
	else   
	{
		for(int i=1;i<iPos-1;i++)
		{
			temp=temp->Next;
		}
		Newn->Next=temp->Next;
		temp->Next->prev=Newn;
		temp->Next=Newn;
		Newn->prev=temp;
		iSize++;
	}	
}

/*
	Function Name : DeleteFirst();
	Function to delete node at first position in linked list
*/
template<class T>
void DoublyLL<T>::DeleteFirst()
{
	if(Head==NULL)// if Linked list is Empty
	{
		return;
	}
	else if(Head->Next==NULL)// If linked list contain single node
	{
		delete(Head);
		Head=NULL;
	}
	else// If linked list contain more the one element/node.				
	{
		struct d_node<T>*temp=Head;
		Head=Head->Next;
		Head->prev=NULL;
		delete(temp);
	}
	iSize--;
	
}

/*
	Function Name : DeleteLast();
	Function to delete last node in the linked list.
*/
template<class T>
void DoublyLL<T>::DeleteLast()
{
	if(Head==NULL)    // If linked list is empty 
	{
		return ;
	}
	else if(Head->Next==NULL)  //If linked list contain single node
	{
		delete(Head);
		Head=NULL;
	}
	else   // If linked list contain more than one node
	{
		struct d_node<T> *temp=Head;
		while(temp->Next->Next!=NULL)
		{
			temp=temp->Next;
		}
		delete(temp->Next);
		temp->Next=NULL;
	}
	iSize--;
}

/*
	Function Name : DeleteAtPos(int);
	Function to delete node at given position in the linked list
*/
template<class T>
void DoublyLL<T>::DeleteAtPos(int iPos)
{
	struct d_node<T>*temp=Head;    // temperory pointer
	struct d_node <T> * target=NULL;
	if((iPos<1)||(iPos>iSize))
	{
		return;
	}
	if(iPos==1)
	{
		DeleteFirst();
	}
	else if(iPos==iSize)
	{
		DeleteLast();
	}
	else
	{
		for(int i=1;i<iPos-1;i++)
		{
			temp=temp->Next;
		}
		target=temp->Next;
		temp->Next=temp->Next->Next;
		temp->Next->prev=temp;
		delete(target);
		iSize--;
	}
}

/*
	Function Name : SearchElement(T)
	Function for to search any element in the linked
*/
template <class T>
bool DoublyLL<T>::SearchElement(T iNo)      //bool is a boolean data type
{
	int i=0,iCnt=0;
	struct d_node<T>*temp=Head;
	for(i=1;i<=iSize;i++)
	{
		if(temp->Data==iNo)
		{
			iCnt++;
			break;
		}
		temp=temp->Next;
	}
	if(iCnt>0)
	{
		return true;
	}
	else
	{
		return false;
	}

}

/*
	Function Name : Frequency(T)
	Function to calculate the frequency of the particular element
*/
template <class T>
int DoublyLL<T>::Frequency(T iNo)
{
	int iCnt=0;
	struct d_node <T> *temp=Head;
	for (int i=1;i<=iSize;i++)
	{
		if(temp->Data==iNo)
		{
			iCnt++;
		}
		temp=temp->Next;
	}
	return iCnt;
}

/*
	Function name : summation()
	Function to calculate the summation of all the element.
*/
template <class T>
T DoublyLL<T>::summation()
{
	T Sum=0;
	struct d_node <T> *temp=Head;
	while(temp!=NULL)
	{
		Sum=Sum+(temp->Data);
		temp=temp->Next;
	}
	return Sum;
}

/*
	Function Name : FirstOccurance(T);
	Function to find first occurance index of the particuler element.
*/
template<class T>
int DoublyLL<T>::FirstOccurance(T iNo)
{
	int i=0;
	struct d_node <T> *temp=Head;
	for(i=1;i<=iSize;i++)
	{
		if((temp->Data)==iNo)
		{
			break;
		}
		temp=temp->Next;
	}
	return i;
}

/*
	Function name : Maximum();
	Function to return the maximum value element from the linked list
*/
template<class T>
T DoublyLL<T>::Maximum()
{
	struct d_node<T>*temp=Head;
	T Max=temp->Data;
	while(temp!=NULL)
	{
		if((temp->Data)>Max)
		{
			Max=temp->Data;
		}
		temp=temp->Next;
	}
	return Max;
}

/*
	Function name : Minimum();
	Function to return the minimum value element from the linked list
*/
template<class T>
T DoublyLL<T>::Minimum()
{
	struct d_node<T>*temp=Head;
	T Min=temp->Data;
	while(temp!=NULL)
	{
		if((temp->Data)<Min)
		{
			Min=temp->Data;
		}
		temp=temp->Next;
	}
	return Min;
}
/*****************************************************
	END OF DOUBLY LINEAR LINKED LIST              
****************************************************

		Subject : Doubly Circular linked list using generic programming 	
*/
template <class T>
class DoublyCL //class declaration for Doubly Circular linklist.
{
	private:
	struct d_node<T>*Head;
	struct d_node<T>*Teil;
	int iSize;
	
	public:
	DoublyCL(); //constructor
	~DoublyCL(); //Destructor
	void InsertFirst(T);
	void InsertLast(T);
	void InsertAtPos(T,int);
	void DeleteFirst();
	void DeleteLast();
	void DeleteAtPos(int);
	int Count();
	void Display();
	bool SearchElement(T);
	int Frequency(T);
	T summation();
	int FirstOccurance(T);
	T Maximum();
	T Minimum();
};

///////////////////////////////////////////////////////////////
// constrictor (constructor is use to allocate the resourses)
///////////////////////////////////////////////////////////////
template<class T>
DoublyCL<T>::DoublyCL() //constructor
{
	Head=NULL;
	Teil=NULL;
	iSize=0;
}

/////////////////////////////////////////////////////////////////
// destructor  (destructor is use to deallocate the resourses)
/////////////////////////////////////////////////////////////////
template<class T> //Destructor 
DoublyCL<T>::~DoublyCL()
{
	struct d_node<T> *temp=Head;
	for(int i=1;i<=iSize;i++)
	{
		temp=Head;
		Head=Head->Next;
		delete(temp);
	}
}

////////////////////////////////////////////////////////////////////////////////////////
// Function Name : Count();
// Count function is use to count the number of element present in the linkedlist.
////////////////////////////////////////////////////////////////////////////////////////
template <class T>
int DoublyCL<T>::Count()
{
	return iSize;
}

////////////////////////////////////////////////////
// Function Name : Display();
//Function to Display contains of the linked list
///////////////////////////////////////////////////
template <class T>
void DoublyCL<T>::Display()
{
	struct d_node<T> *temp=Head;
	for(int i=1;i<=iSize;i++)
	{
		cout<<temp->Data<<"\t";
		temp=temp->Next;
	}
	cout<<"\n";
}

////////////////////////////////////////////////
//Function Name : InsertFirst(T);
//	To insert the element at the first position
///////////////////////////////////////////////
template<class T>
void DoublyCL<T>::InsertFirst(T iNo)
{
	struct d_node<T> *Newn=NULL;
	Newn=new struct d_node<T>;
	Newn->Data=iNo;
	Newn->Next=NULL;
	Newn->prev=NULL;
	if(Head==NULL)
	{
		Head=Newn;
		Teil=Newn;
	}
	else
	{
		Newn->Next=Head;
		Head->prev=Newn;
		Head=Newn;
		Teil->Next=Head;
		Head->prev=Teil;
	}
	iSize++;
}

///////////////////////////////////////////////////
// Function Name : InsertLast(T);
//	Function to insert last element in linked list
//////////////////////////////////////////////////
template<class T>
void DoublyCL<T>::InsertLast(T iNo )
{
	struct d_node<T>*Newn=NULL;
	Newn=new struct d_node<T>;
	Newn->Data=iNo;
	Newn->Next=NULL;
	Newn->prev=NULL;
	if(Head==NULL)
	{
		Head=Newn;
		Teil=Newn;
	}
	else
	{
		Teil->Next=Newn;
		Newn->prev=Teil;
		Teil=Teil->Next;
		Teil->Next=Head;
		Head->prev=Teil;
	}
	iSize++;
}

/////////////////////////////////////////////////////////////
// Function Name : InsertAtPos(T,int);
//Function to insert node at given position in linked list
/////////////////////////////////////////////////////////////
template<class T>
void DoublyCL<T>::InsertAtPos(T iNo,int iPos)
{
	struct d_node <T>*temp=Head;
	struct d_node<T>*Newn=NULL;
	Newn=new struct d_node<T>;
	Newn->Data=iNo;
	Newn->Next=NULL;
	Newn->prev=NULL;
	if((iPos<1)||(iPos>iSize+1))
	{
		cout<<"Please enter valid position\n";
		return;
	}
	if(iPos==1)// If insert at 1st position then internally call InsertFirst() 
	{
		InsertFirst(iNo);
	}
	else if(iPos==iSize+1) // If insert at last position then internally call InsertLast()
	{
		InsertLast(iNo);
	}
	else   
	{
		for(int i=1;i<iPos-1;i++)
		{
			temp=temp->Next;
		}
		Newn->Next=temp->Next;
		temp->Next->prev=Newn;
		temp->Next=Newn;
		Newn->prev=temp;
		iSize++;
	}	
}

/////////////////////////////////////////////////////////////
// Function Name : DeleteFirst();
// Function to delete node at first position in linked list
/////////////////////////////////////////////////////////////
template<class T>
void DoublyCL<T>::DeleteFirst()
{
	if(Head==NULL)  // if Linked list is Empty
	{
		return;
	}
	else if(Head->Next==NULL)  // If linked list contain single node
	{
		delete(Head);
		Head=NULL;
		Teil=NULL;
	}
	else		// If linked list contain more the one element/node.				
	{
		struct d_node<T>*temp=Head;
		Head=Head->Next;
		Head->prev=Teil;
		Teil->Next=Head;
		delete(temp);
	}
	iSize--;
	
}

////////////////////////////////////////////////////
// Function Name : DeleteLast();
// Function to delete last node in the linked list.
////////////////////////////////////////////////////
template<class T>
void DoublyCL<T>::DeleteLast()
{
	if(Head==NULL)// If linked list is empty 
	{
		return ;
	}
	else if(Head->Next==NULL)//If linked list contain single node
	{
		delete(Head);
		Head=NULL;
		Teil=NULL;
	}
	else// If linked list contain more than one node
	{
		Teil=Teil->prev;
		delete(Teil->Next);
		Teil->Next=Head;
		Head->prev=Teil;
	}
	iSize--;
}

///////////////////////////////////////////////////////////////////
// Function Name : DeleteAtPos(int);
// Function to delete node at given position in the linked list
//////////////////////////////////////////////////////////////////
template<class T>
void DoublyCL<T>::DeleteAtPos(int iPos)
{
	struct d_node<T>*temp=Head;// temperory pointer
	struct d_node <T> * target=NULL;
	if((iPos<1)||(iPos>iSize))
	{
		return;
	}
	if(iPos==1)
	{
		DeleteFirst();
	}
	else if(iPos==iSize)
	{
		DeleteLast();
	}
	else
	{
		for(int i=1;i<iPos-1;i++)
		{
			temp=temp->Next;
		}
		target=temp->Next;
		temp->Next=temp->Next->Next;
		temp->Next->prev=temp;
		delete(target);
		iSize--;
	}
}

////////////////////////////////////////////////////////
// Function Name : SearchElement(T)
// Function for to search any element in the linked
////////////////////////////////////////////////////////
template <class T>
bool DoublyCL<T>::SearchElement(T iNo)//bool is a boolean data type
{
	int i=0,iCnt=0;
	struct d_node<T>*temp=Head;
	for(i=1;i<=iSize;i++)
	{
		if(temp->Data==iNo)
		{
			iCnt++;
			break;
		}
		temp=temp->Next;
	}
	if(iCnt>0)
	{
		return true;
	}
	else
	{
		return false;
	}

}

/*******************
	Function Name : Frequency(T)
	Function to calculate the frequency of the particular element
	
*******************/
template <class T>
int DoublyCL<T>::Frequency(T iNo)
{
	int iCnt=0;
	struct d_node <T> *temp=Head;
	for (int i=1;i<=iSize;i++)
	{
		if(temp->Data==iNo)
		{
			iCnt++;
		}
		temp=temp->Next;
	}
	return iCnt;
}

/*******************
	Function name : summation()
	Function to calculate the summation of all the element.

*******************/
template <class T>
T DoublyCL<T>::summation()
{
	T Sum=0;
	struct d_node <T> *temp=Head;
	for(int i=1;i<=iSize;i++)
	{
		Sum=Sum+(temp->Data);
		temp=temp->Next;
	}
	return Sum;
}

/*******************
	Function Name : FirstOccurance(T);
	Function to find first occurance index of the particuler element.
********************/
template<class T>
int DoublyCL<T>::FirstOccurance(T iNo)
{
	int i=0;
	struct d_node <T> *temp=Head;
	for(i=1;i<=iSize;i++)
	{
		if((temp->Data)==iNo)
		{
			break;
		}
		temp=temp->Next;
	}
	return i;
}

/*******************
	Function name : Maximum();
	Function to return the maximum value element from the linked list

******************/
template<class T>
T DoublyCL<T>::Maximum()
{
	struct d_node<T>*temp=Head;
	T Max=temp->Data;
	for(int i=1;i<=iSize;i++)
	{
		if((temp->Data)>Max)
		{
			Max=temp->Data;
		}
		temp=temp->Next;
	}
	return Max;
}

/********************
	Function name : Minimum();
	Function to return the minimum value element from the linked list
	
********************/
template<class T>
T DoublyCL<T>::Minimum()
{
	struct d_node<T>*temp=Head;
	T Min=temp->Data;
	for(int i=1;i<=iSize;i++)
	{
		if((temp->Data)<Min)
		{
			Min=temp->Data;
		}
		temp=temp->Next;
	}
	return Min;
}
/*************************************
  END OF DOUBLY CIRCULAR LINKED LIST
************************************/
///////////////////////////////////////////
/////////////////
//////////////             STACK
////////////////
//////////////////////////////////////////

template <class T>
struct node_s
{
	T Data;
	struct node_s *Next;
};

template <class T>
class Stack
{
	private:
	struct node_s<T> *Head;
	int iSize;
	
	public:
	Stack();//Constructor
	~Stack();//Destructor
	void push(T);//void InsertFirst(int);
	int pop();//void DeleteFirst();
	int peek();
	void Display();
	int Count();
};


// constructor 
template <class T>
Stack<T>::Stack()//Constuctor
{
	cout<<"Inside Constructor\n";
	Head=NULL;
	iSize=0;
}


// destructor
template <class T>
Stack<T>::~Stack()
{
	cout<<"Inside Desrtuctor\n";
	struct node_s <T>*temp=NULL;
	while(Head!=NULL)
	{
		temp=Head;
		Head=Head->Next;
		delete(temp);
	}
}

/***********************
	push fucnction is used to add element  
	Into the stack (like InsertFirst() 
	
***********************/
template <class T>
void Stack<T>::push(T iValue)
{
	struct node_s <T> *Newn=NULL;
	Newn=new struct node_s<T>;
	Newn->Data=iValue;
	Newn->Next=NULL;
	
	Newn->Next=Head;
	Head=Newn;
	iSize++;
}

/*********************
	pop is use to delete first element like 
	(like DeleteFirst() in linked list ) 
	
*********************/

template <class T>
int Stack<T>::pop()   //DeleteFirst()
{
	int iRet=-1;
	if(iSize==0)
	{
		cout<<"Stack is Empty\n";
	}
	else
	{
		struct node_s <T> *temp=Head;
		Head=Head->Next;
		iRet=temp->Data;
		delete(temp);
		iSize--;
	}
	return iRet;
}

/*********************
 Peek function is use for the display the Top element in the stack 
*********************/
template <class T>
int Stack<T>::peek()
{
	if(iSize==0)
	{
		cout<<"Stack is empy";
		return -1;
	}
	else
	{
		return Head->Data;
	}
}

///////////////////
// Display ///////
/////////////////
template <class T>
void Stack <T>::Display()
{
	struct node_s<T> *temp=Head;
	while(temp!=NULL)
	{
		cout<<"|"<<temp->Data<<"|->";
		temp=temp->Next;
	}
	cout<<"NULL\n";
}

////////////////////
// Count  ////////
/////////////////
template <class T>
int Stack<T>::Count()
{
	return iSize;
}
/////////////////////////////////////
////////////////
////////////					Queue
///////////////
/////////////////////////////////////

template <class T>
struct node_q
{
	T Data;
	struct node_q *Next;
	//self referencing pointer 
};

template <class T>
class Queue
{
	private:
	struct node_q <T> *Head;
	int iSize;
	
	public:
	Queue();
	~Queue();
	void enQueue(int);//void InsertLast(int);
	int dQueue();
	void Display();
	int Count();
};

template <class T>
Queue<T>::Queue()
{
	Head=NULL;
	iSize=0;
}

template <class T>
Queue<T>::~Queue()
{
	struct node_q<T> *temp=NULL;
	while(Head!=NULL)
	{
		temp=Head;
		Head=Head->Next;
		delete(temp);
	}
}

template <class T>
void Queue<T>::enQueue(int iValue)//InsertLast()
{
	struct node_q <T> *temp=Head;
	struct node_q <T> *Newn=new struct node_q<T>;
	Newn->Data=iValue;
	Newn->Next=NULL;
	if(Head == NULL)
	{
		Head=Newn;
	}
	else
	{
		while(temp->Next != NULL)
		{
			temp=temp->Next;
		}
		temp->Next=Newn;
	}
	iSize++;
}

template <class T>
int Queue<T>::dQueue()//DeleteFirst
{
	int iRet=0;
	if(Head==NULL)
	{
		cout<<"Queue is Empty\n";
	}
	else
	{
		struct node_q <T> *temp=Head;
		Head=Head->Next;
		iRet=temp->Data;
		delete(temp);
		iSize--;
	}
	return iRet;
}

template <class T>
void Queue<T>::Display()
{
	struct node_q<T> *temp=Head;
	while(temp!=NULL)
	{
		cout<<"|"<<temp->Data<<"|->";
		temp=temp->Next;
	}
	cout<<"NULL\n";
}

template <class T>
int Queue<T>::Count()
{
	return iSize;
}
/********************************
	BUBBLE SORT
*********************************/
template <class T>
struct node<T> *swap(struct node<T> *ptr1,struct node<T> *ptr2)
{
	struct node<T> *temp = ptr2->Next;
	ptr2->Next = ptr1;
	ptr1->Next = temp;
	return ptr2;
};

template <class T>
void bubbleSort(struct node<T> **Head)
{
	int size=0,i=0,j=0;
	bool sorted = true;//flag
	size = Count(*Head);
	struct node<T> **temp=NULL;
	
	for(i=0;i<=size;i++)
	{
		temp=Head;
		
		for(j=0;j<size-i-1;j++)
		{
			struct node<T> *ptr1 = *temp;
			struct node<T> *ptr2 = ptr1->Next;
			
			if((ptr1->Data) > (ptr2->Data))
			{
				*temp = swap(ptr1,ptr2);
				sorted = false;
			}
			temp=&(*temp)->Next;
		}
		if(sorted == true)
		{
			break;
		}
	}
}
//***********************