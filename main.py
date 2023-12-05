



def Szyfr(code,text,what):
    
    text = text.upper()
    if what == "sz":
        with open('C:\\Users\\Student\\Desktop\\Nowy folder\\in2.txt', 'r') as f:
            text = f.read()
            result = ""
            for znak in text :
                result += chr((ord(znak) - 65 + code) % 26 +65)
            return result
    elif what == "de":    
        result = ""
        for znak in text :
            result += chr((ord(znak) - 65 - code) % 26 +65)
        return result
    else:
        return "Brak decyzji."
#Napisz program, który wczytuje dane z dwóch plików: in.txt i dict.txt. Plik in.txt zawiera dowolny
#tekst w języku polskim. Plik dict.txt zawiera słownik wyrazów języka polskiego składających się z
#małych liter, jeden pod drugim. Przy pierwszym uruchomieniu plik dict.txt nie istnieje. Po
#załadowaniu plików in.txt i dict.txt (lub utworzeniu pliku dict.txt) program analizuje dane
#wejściowe (in.txt) i uzupełnia słownik o nowe wyrazy. Każdy wyraz w słowniku może wystąpić tylko
#raz.



def dictionary():
    
    with open('C:\\Users\\Student\\Desktop\\Nowy folder\\in.txt', 'r') as f:
        words = f.read().split()
    try:
        with open('C:\\Users\\Student\\Desktop\\Nowy folder\\dict.txt', 'r') as f:
            d = set(line.strip() for line in f)
    except FileNotFoundError:
        with open('C:\\Users\\Student\\Desktop\\Nowy folder\\dict.txt', 'w') as f:
            pass

    d.update(word.lower() for word in words)

    with    open('C:\\Users\\Student\\Desktop\\Nowy folder\\dict.txt', 'w') as f:
        for word in d:

            f.write(word + '\n')
    
    f.close()


dictionary()

what = input("Co chcesz zrobic? (sz- szyfrowanie, de - deszyfrowanie)   ")
code =  int(input("Podaj kod: "))
print(Szyfr(code,text,what))