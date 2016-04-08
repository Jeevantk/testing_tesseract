#include <iostream>

using namespace std;

int main()
{
  string s="IIIIIll";
  int flag=0;
  int count=0;
  if (s.length()<3)flag=1;
  for(int j=0;j<s.length();j++)
  {
    if(s[j]!='i'&&s[j]!='I'&&s[j]!='l'&&s[j]!='L'&&s[j]!='1')
    {
      count++;
    }
  }
  if (count<3)flag=1;
  cout << flag<<endl;
}

/*
WhenthewoodsandforestgladesIwanIhearthe
ButwhenIthinkthatHisSonnotsparsentHimto
WhenChristshallwithshoutofacclamandtakeme
IIIIIll
II
3h
t
IiII1
alltheThyhandhathIseetheIhearthethighty
birdssinginthetreesgwhenIlookdownfromIofty
Iscarcecantakeitthatonthecrossmyglad1y
whatioyshallfillmyheartlThenIshallbowina
I
I
kI
vIIl
IIIIIIIIrtIII
IlIIIIIIIIIII1I
IIIIII
Thytheunismgsmy
granandhearthebrookandfeelthegentle
bearingHebledanddiedtotakeawaymy
tiouandthereprouMygreatThou
n
IllIIIlI
lIUII
mytoHowgreatThouHowgreatThouartlThensingsmy*/
