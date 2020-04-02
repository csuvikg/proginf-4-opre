# Megjegyzések
 - A beadandó határideje ki lett tolva egy héttel, mert az évfolyam fele nem adta le
 - Ezalatt az is adhat be javítást, aki már leadta

# Signal
 - Jelzés egyik folyamatból a másikba
 - kill -> signal küldő parancs, kill -l listázza a signalokat
 - minden folyamathoz tartozik két tábla, ami a signalokat kezeli, az adott biteket billenti
 - sigaction value-val adatot is lehet küldeni a signalhoz
 - timer: itimer
 - vannak realtime signalok: garantálva van, hogy megérkezik azonnal
    - a nevében van az rt, illetve van a nevében egy prioritás
    - ha ilyet használunk, gcc -lrt flaggel fordítható
