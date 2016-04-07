# Gjennomgang av eksempelkoden

Eksempelkoden i `main.cpp` kan simulere et system av sammenkoblede noder som dyttes av en fjær. Det er ikke lagt på noen friksjonelov -- det blir opp til dere å legge til. Alle modellparametrene settes inne i selve programmet. Dette inkluderer navnet på filene som utdata sendes til. Dette kodeeksempelet er gitt for å vise et eksempel på hvordan man begynner å lage en friksjonskode. Vi har valgt å ikke lage en objektorientert kode i første omgang, for å gjøre det lettere for dere å venne seg til C++. Når dere lager deres egen kode, kan det hende dere på et eller annet tidspunkt opplever at koden blir såpass kompleks at det er hensiktsmessig å objektorientere den (bruke klasser). Da vil vi selvfølgelig hjelpe dere med det.

De to første kommandoene inkluderer biblioteker som blant annet gir tilgang til å skrive til terminal vha std::cout << <tekst> og skrive til fil med std::ofstream.write(<tekst/tall>)

Kommandoen `using namespace std` gjør at man slipper å skrive `std::` foran funksjoner i standardbiblioteket, slik at `std::cout` kan skrives `cout` 

Videre følger der vi kaller "forward declarations" av funksjoner. Det er for å fortelle at disse funksjonene eksisterer og hvilke inn- og utvariable de har. Når kompilatoren går igjennom programmet leser den fra toppen og nedover, men dersom en funksjon har blitt "forward declared" vil kompilatoren gå igjennom hele koden og finne ut hvordan implementasjonen av denne funksjonen ser ut. (Selve implementasjonen av funksjonene har jeg valgt å gjøre under `main`-funksjonen.

Deretter følger `main`-funksjonen. Det er denne funksjonen som kjøres når man kjører det ferdig kompilerte programmet. Det betyr at alle operasjoner man skal gjøre på en eller annen måte må skrives inn her (men man kan selvfølgelig kalle på andre funksjoner fra innsiden av `main`-funksjonen.)

Øverst i `main`-funksjonen har jeg definert og gitt verdier til en del variable som er parametre i friksjonsmodellen. Dette er ting som antall noder i modellen, massen til hele klossen og fjærstivheten mellom nodene. 

Videre følger to kommandoer der det opprettes objekter av typen `ofstream`. Dette er en type objekter som lar oss sende data for eksempel til en fil (i dette tilfellet data fra simuleringen).

Deretter allokeres det minne som skal brukes til å ha lagre tilstanden til systemet vi simulerer. Dette er i første omgang arrays for posisjoner, hastigheter og krefter (senere vil det bli nødvendig å allokere minne for å lagre informasjon om friksjonstilstanden også). Når man allokerer minne til arrays i C++, så er man ikke garantert at verdiene settes til 0. Derfor settes verdiene eksplisitt til 0 i en løkke (unntatt posisjonsarrayen, der verdiene settes til posisjonene til nodene ved start). 

Videre følger en ny løkke, og det er i denne løkken programmet gjør det meste av jobben. Det er en kraftberegning `calculateForces()`, og et integrasjonssteg `integrate()`. Så gjøres det en test for å sjekke om det skal skrives data til fil. Vi ønsker ikke å skrive ut data fra hvert eneste tidssteg, rett og slett fordi det ville tatt for mye plass på harddisken. 

Videre nedover foregår det litt "opprydning". Vi skriver ut parameterverdier til fil, for å sikre at de numeriske simuleringene blir reproduserbare. Deretter lukker vi `ofstream`-objektene. Disse må lukkes for å sikre at alle dataene faktisk skrives til fil (ofstream mellomlagrer data i minne, og venter med å skrive til fil til den har samlet opp en viss mengde data).

Under `main`-funksjonen finner man funksjoner som `main`-funksjonen kaller på. `calculateForces`-funskjonen tar parametre og tilstand som input, og endrer krafttilstanden til systemet. `integrate` tar tilstanden til systemet og kjører et steg med Euler--Cromers metode. `springForce` beregner kraften i en fjær, og brukes av `calculateForces`-funksjoen. `writeArrayToFile` skriver data til fil. 

For å lære C++ anbefaler vi for eksempel å bruke tutorialen på www.cplusplus.com/doc/tutorial/ eller å kjøpe "Sams Teach Yourself C++ in One Hour a Day (7th Edition)" som vanligvis finnes på amazon (også kindle) og akademika. 

Om man vil vite mer nøyaktig hva funksjonene i standarbiblioteket gjør, kan man gå inn på for eksempel www.cppreference.com eller www.cplusplus.com og søke på den aktuelle funksjonen. På disse nettsidene ligger det vanligvis langt mer informasjon enn det man trenger, og mye av det som står der er vanskelig å forstå uten en bachelorgrad i informatikk, men eksemplene er gjerne nyttige. 


