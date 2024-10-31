English Version
GNSS Logger (made by 5623)
Project Overview

This program connects to a GNSS module (model used: MC60), paired with an antenna (e.g., Mitcom), to collect and log location data. It records the full range of data as well as GGA format messages in log files, with URL links for visualizing coordinates on Google Maps.
Key Functionality

    Startup Checks: The program verifies the GNSS module status on startup and activates it if necessary.
    File Naming: Users can specify a custom file name. By default, the file is named with the date and time.
    Data Logging: The program generates and stores three separate files:
        log_name.txt - all program activities.
        gps_name.txt - all received data.
        gga_name.txt - GGA format data (lines with $GGA).
    Shutdown: Pressing Ctrl+C ends the program, automatically turning off the GNSS interface and offering the option to fully power down the GNSS module.

Known Issues (Bugs)

    Serial Port Busy (picocom): If another process, such as picocom, occupies the serial port, the program will not work correctly. It is recommended to stop the picocom process before running this program.
    First Character of Filename: Sometimes, the first character of the file name input is "eaten." To avoid this, enter the name from the second character or repeat the first character.

Compilation Instructions

Use the following command to compile the executable file:

bash

g++ -o Your_name main.cpp gnss.cpp gpio_module.cpp file_logger.cpp map_url_generator.cpp serial.cpp -I.

Creating an Alias for Quick Access

On Linux, you can create an alias for easy program access (in this case, named GNSS).
Open the .bashrc file (or .zshrc, depending on your terminal) in your home directory:

bash

nano ~/.bashrc

Add the following line:

bash

alias gnss_run='/path/to/GNSS'

Replace /path/to/GNSS with the path to your directory.
Polish Version
GNSS Logger (zrobione przez 5623)
Opis Projektu

Program łączy się z modułem GNSS (używany model: MC60) i anteną (np. Mitcom), aby zbierać i logować dane o lokalizacji. Program zapisuje pełen zakres danych, jak również dane w formacie GGA w plikach logów, dodając link do Google Maps dla wizualizacji współrzędnych.
Główna Funkcjonalność

    Sprawdzenie i przygotowanie do pracy: Program sprawdza status modułu GNSS podczas uruchomienia i aktywuje go, jeśli jest to konieczne.
    Wprowadzenie nazwy pliku: Użytkownik może ustawić własną nazwę pliku dla logów. Domyślnie nazwa jest generowana automatycznie, zawierając datę i godzinę.
    Zapis danych: Program tworzy i zapisuje trzy osobne pliki:
        log_nazwa.txt - wszystkie działania programu.
        gps_nazwa.txt - wszystkie odebrane dane.
        gga_nazwa.txt - dane w formacie GGA (linie z $GGA).
    Zakończenie pracy: Naciśnięcie Ctrl+C kończy działanie programu, automatycznie wyłączając interfejs GNSS i oferując opcję całkowitego wyłączenia modułu GNSS.

Znane błędy

    Zajęty port picocom: Jeśli inny proces, np. picocom, zajmuje port szeregowy, program nie będzie działał poprawnie. Zaleca się zatrzymać proces picocom przed uruchomieniem programu.
    Pierwszy znak nazwy pliku: Czasami pierwszy znak nazwy pliku jest "zjadany." Aby tego uniknąć, wprowadź nazwę od drugiego znaku lub powtórz pierwszy znak.

Instrukcja Kompilacji

Aby skompilować plik wykonywalny, użyj następującej komendy:

bash

g++ -o Your_name main.cpp gnss.cpp gpio_module.cpp file_logger.cpp map_url_generator.cpp serial.cpp -I.

Tworzenie Aliasu dla Szybkiego Dostępu

Na systemie Linux można utworzyć alias do łatwego uruchamiania programu (w tym przypadku nazwa GNSS).
Otwórz plik .bashrc (lub .zshrc, zależnie od terminala) w swoim katalogu domowym:

bash

nano ~/.bashrc

Dodaj następującą linię:

bash

alias gnss_run='/path/to/GNSS'

Zamień /path/to/GNSS na ścieżkę do katalogu.
Ukrainian Version
GNSS Logger (made by 5623)
Опис проєкту

Програма створена для підключення до GNSS-модуля (використовувалася модель: MC60), який працює разом з антеною (наприклад, Mitcom), для зчитування та логування даних про місцезнаходження. Програма записує як повний обсяг даних, так і повідомлення формату GGA у лог-файли, додаючи до них URL для відображення координат на Google Maps.
Основний функціонал

    Перевірка та підготовка до роботи: Програма перевіряє статус модуля GNSS на старті, активує його, якщо потрібно.
    Введення імені файлу: Користувач може задати власне ім’я для лог-файлів. За замовчуванням генерується назва з датою та часом.
    Запис даних: Програма створює та зберігає три окремих файли:
        log_назва.txt - усі дії програми.
        gps_назва.txt - усі отримані дані.
        gga_назва.txt - дані формату GGA (рядки з $GGA).
    Завершення роботи: При натисканні Ctrl+C програма завершує роботу, автоматично відключаючи GNSS-інтерфейс, і пропонує повністю вимкнути GNSS-модуль.

Відомі помилки (bugs)

    Зайнятість порту picocom: Якщо інший процес, як-от picocom, використовує серійний порт, програма не зможе коректно працювати. Рекомендується зупинити процес picocom перед запуском.
    Помилка з першим символом імені файлу: При введенні імені файлу інколи "з'їдається" перший символ. Щоб уникнути цього, введіть ім'я з другого символу або додайте перший символ повторно.

Інструкції з компіляції

Для компіляції виконавчого файлу виконайте наступну команду:

bash

g++ -o Your_name main.cpp gnss.cpp gpio_module.cpp file_logger.cpp map_url_generator.cpp serial.cpp -I.

Для створення alias для швидкого

В Linux можна створити аліас для зручного запуску програми (в даному випадку з назвою GNSS).
Відкрийте файл .bashrc (або .zshrc, залежно від використовуваного терміналу) в домашній директорії:

bash

nano ~/.bashrc

Додайте рядок:

bash

alias gnss_run='/path/to/GNSS'

Замініть /path/to/GNSS на шлях до вашої директорії.
