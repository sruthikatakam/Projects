//	bank.org	2013 apr 15	last modified 2014 feb 21
//
//	Shows organization of instructor's bank.cpp.
//

#include <fstream>
#include <iomanip>
#include <iostream>
#include <new.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

	struct cust {
		int cusn;	// customer number	
		int entr;	// when entered
		int jtim;	// time needed by clerk to do customer's job
		cust *link;
	} *custh;		// pointer to head node
	struct evnt {
		int time;	// cusn enters, or clrk done	
		int what;	// 1: customer enters; 2: clerk finishes job
		int whom;	// if 1: cusn; if 2: clrk
		int data;	// if 1: jtim; if 2: cusn
		evnt *link;
	} *evnth;		// pointer to head node
	struct idlq {
		int clrk;	// which clerk
		int time;	// when began idle
		idlq *link;
	} *idlqh;		// pointer to head node
 	struct watq {
		int cusn;	// customer number
		int entr;	// when entered	
		int jtim;	// time needed by clerk to do customer's job
		watq *link;
	} *watqh,*watqt;	// pointers to head node, tail node

	int const infinity=2147483647;			// 2**31 - 1
	int *idle,maxwait,minwait,now,totwait;

int
main( int argc,char **argv )
{
	int newerr( size_t );
	void readjobs( char *,int & ),simul( int,int,int,int ),
		stats( int,int );

	cust *p,*q;
	int i,m,m0,m1,n,v=0;

	if ( (argc < 4) || (5 < argc) ) {
		cout << "** use is >bank [-v] nclerk0 nclerk1 file **\n";
		exit( 1 );
	}
	_set_new_handler( newerr );
	if ( strcmp( *++argv,"-v" ) == 0 ) {
		v++;
	} else {
		--argv;
	}
	m0 = atoi( *++argv );
	m1 = atoi( *++argv );
	if ( (m0 < 1) || (m1 < m0) ) {
		cout << "** bad nclerk0 and/or nclerk1 **\n";
		exit( 1 );
	}
	idle = new int [m1];
	readjobs( *++argv,n );
	cout.setf( ios::fixed,ios::floatfield );
	cout.setf( ios::showpoint );
	for ( m = m0;  m <= m1;  m++ ) {
		cout << setw( 3 ) << m << " clerk" << (m < 2 ? "" : "s")
			<< " --\n";
		for ( i = 0;  i < 2;  i++ ) {
			simul( i,v,n,m );
			cout << (i == 0 ? "FCFS:" : " SJF:") << " finish at "
				<< now << '\n';
			stats( n,m );
		}
		cout << '\n';
	}
	for ( p = custh;  p != (cust *)0; ) {
		q = p->link;
		delete p;
		p = q;
	}
	delete [] idle;
	return( 0 );
}
void
addevnt( evnt *pevnt )
{
	evnt *p,*q;
}			
void
getcust( int clrk )
{
	void addevnt( evnt * );

	evnt *pevnt;
	watq *q;
	int wait;
}
void
init( int n,int m )
{
	cust *pcust;
	evnt *pevnt,*q;
	idlq *pidlq,*r;
	int i;
}
int
newerr( size_t x )
{
	cout << "** new has failed **\n";
	exit( 1 );
}
void
readjobs( char *fname,int & n )
{
	ifstream file;
	struct {
		unsigned short int entr;
		unsigned short int jtim;
	} rec;
	cust *pcust,*q;
}
void
simul( int mode,int v,int n,int m )
{
	void getcust( int ),init( int,int ),showevnt( void ),toclrk( int,int ),
		toidlq( int ),towatq( int,int,int );

	evnt *q;
	int clrk,data,jtim,what,whom;
void
stats( int n,int m)
{
	int i,maxidle,minidle,totidle;
}
void
toclrk( int cusn,int jtim )
{
	void addevnt( evnt * );

	evnt *p;
	idlq *q;
	int clrk;
}
void
toidlq( int clrk )
{
	idlq *p,*pidlq,*q;
}
void
towatq( int mode,int cusn,int jtim )
{
	watq *p,*pwatq,*q;
}
