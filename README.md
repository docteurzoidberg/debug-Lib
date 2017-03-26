# debug-Lib
Librairie de debug en c++ inspiré de Winston (lib nodejs)

## Level de debug

5 niveaux : Error, Warning, Log, Info et Verbose

## Utilisation
Pour écrire des messages dans les niveaux correspondants

```C++
Logger::error(std::string msg)
``` 
```C++
Logger::warning(std::string msg)
``` 

```C++
Logger::log(std::string msg)
```

```C++
Logger::info(std::string msg)
```

```C++
Logger::verbose(std::string msg)
```

## Redirection des flux
Par défaut le flux est std::cout pour tous

Pour rediriger vers n'importe quel flux
```C++
Logger::redirectTo(unsigned int levels, std::ostream os)
```

Pour rediriger vers un fichier
```C++
Logger::redirectToFile(unsigned int levels, char* const path)
```

## Section
Afin de définir des sections

Commence une section "name" et l'affiche sur les niveaux "levels"
```C++
Logger::beginSection(std::string name, unsigned int levels)
```

Termine la section "name"
```C++
Logger::endSection(std::string name)
```

Affiche la section "name" et l'affiche  sur les niveaux levels
```C++
Logger::showSection(std::string name, unsigned int levels)
```

Cache la section "name"
```C++
Logger::hideSection(std::string name)
```

## Format
Le format actuel est : 
`<Date> <Hours> <level> - <message>`
avec Date : dd/mm/yy
et Hours : hh:mm:ss

Pour ne pas les afficher : 
```C++
void setDatePrinting (bool b)
void setHourPrinting (bool b)
```
Par défaut seule l'heure est affiché

