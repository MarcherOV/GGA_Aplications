#Polish# version
# GNSS Logger (zrobione przez 5623)
## Opis Projektu
Program łączy się z modułem GNSS (używany model: MC60) i anteną (np. Mitcom), aby zbierać i logować dane o lokalizacji. Program zapisuje pełen zakres danych, jak również dane w formacie GGA w plikach logów, dodając link do Google Maps dla wizualizacji współrzędnych.
#Główna Funkcjonalność
    Sprawdzenie i przygotowanie do pracy: Program sprawdza status modułu GNSS podczas uruchomienia i aktywuje go, jeśli jest to konieczne.
    Wprowadzenie nazwy pliku: Użytkownik może ustawić własną nazwę pliku dla logów. Domyślnie nazwa jest generowana automatycznie, zawierając datę i godzinę.
    Zapis danych: Program tworzy i zapisuje trzy osobne pliki:
        log_nazwa.txt - wszystkie działania programu.
        gps_nazwa.txt - wszystkie odebrane dane.
        gga_nazwa.txt - dane w formacie GGA (linie z $GGA).
    Zakończenie pracy: Naciśnięcie Ctrl+C kończy działanie programu, automatycznie wyłączając interfejs GNSS i oferując opcję całkowitego wyłączenia modułu GNSS.
#Znane błędy
    Zajęty port picocom: Jeśli inny proces, np. picocom, zajmuje port szeregowy, program nie będzie działał poprawnie. Zaleca się zatrzymać proces picocom przed uruchomieniem programu.
    Pierwszy znak nazwy pliku: Czasami pierwszy znak nazwy pliku jest "zjadany." Aby tego uniknąć, wprowadź nazwę od drugiego znaku lub powtórz pierwszy znak.
#Instrukcja Kompilacji
Aby skompilować plik wykonywalny, użyj następującej komendy:
g++ -o Your_name main.cpp gnss.cpp gpio_module.cpp file_logger.cpp map_url_generator.cpp serial.cpp -I.
#Tworzenie Aliasu dla Szybkiego Dostępu
Na systemie Linux można utworzyć alias do łatwego uruchamiania programu (w tym przypadku nazwa GNSS).
Otwórz plik .bashrc (lub .zshrc, zależnie od terminala) w swoim katalogu domowym:
nano ~/.bashrc
Dodaj następującą linię:
alias gnss_run='/path/to/GNSS'
Zamień '/path/to/GNSS' na ścieżkę do katalogu.
