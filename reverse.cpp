//	reverse.org	1993 jan 13	last modified 2014 feb 06
//
//	Modified from reverse.cpp.
//	Shows "organization" of instructor's reverse.cpp.

#include <iostream>
#include <new.h>
#include <stdlib.h>

using namespace std;

	struct node {
		char atom;			// 0 or 1
		char data;			// if atom: actual data
		node *link;			// ptr to list
		node *next;			// ptr to next node
	};
	node * const nill=(node *)0;
	int const maxs=80;			// max string length
	char const lefp='(',newl='\n',ritp=')';
	node *stack[maxs >> 1],**top=stack-1;	// max stack size <= maxs/2
int
main()
{
	node *linklist( const char * );
	int getstring( char * ),newerr( size_t ),ok( const char * );
	void deleteblanks( char * ),drawline( void ),echoprint( const char * ),
		eraselist( node * ),revlist( const node * ),
		revstring( const char * ),scanlist( const node * );

	node *head;				// ptr to list structure
	char s[maxs+1];				// data string; length <= maxs

	_set_new_handler( newerr );		// defined in new.h
	while ( getstring( s ) ) {
		echoprint( s );
		deleteblanks( s );
		if ( !ok( s ) ) {
			cout << "** illegal list format **\n";
		} else {
			revstring( s );
			head = linklist( s );
			scanlist( head );
			revlist( head );
			eraselist( head );
		}
	}
	drawline();
	return( 0 );
}
void
deleteblanks( char *s )
{
	char *p,*q;
}
void
drawline()
{
	int i;
}
void
echoprint( const char *s )
{
}
void
eraselist( node *p )
{
}
int
getstring( char *s )
{
	void drawline( void );
}
node *
linklist( const char *s )
{
	node *newnode( void );
	void pop( node *&  ),push( node * );

	node *p=nill,*q;
	int lp;
	char ch;
}
int
newerr( size_t x )
{
	cout << "** can't allocate space for node **\n";
	exit( 1 );
}
node *
newnode()
{
	node *q;
}
int
ok( const char *s )					// Assumes s non-empty.
{
	int n=0;
}
void
pop( node *& p )
{
}
void
push( node *p )
{
}
void
rev( const node *p )
{
}
void
revlist( const node *p )
{
	void rev( const node * );
}
void
revstring( const char *s )
{
	const char *p;
	char ch;
}
void
scan( const node *p )
{
}
void
scanlist( const node *p )
{
	void scan( const node * );
}
