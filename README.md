Apache Log Reader

Ce projet est un outil en C qui permet de lire les logs d'un serveur Apache en temps réel et d'offrir plusieurs options d'affichage. Vous pouvez consulter les logs dans le terminal, sous forme graphique ou textuelle, ou encore les visualiser via une interface web en accédant à 127.0.0.1.

Fonctionnalités

Lecture des logs d'Apache en temps réel.

Affichage graphique.

Mode texte dans le terminal.

Interface web accessible sur 127.0.0.1 pour une visualisation interactive.

Prérequis

Serveur Apache allumé au démarrage
Pour cela, utilisez la commande suivante :

sudo systemctl enable apache2

Compilation

Effectuez les commandes suivantes dans le dossier src :

make
make install

Utilisation

Modes de lecture

Mode graphique dans le terminal :

./versiondynamique -gr

Mode texte :

./versiondynamique -txt

Mode web :

Lancez l'application, puis ouvrez votre navigateur à l'adresse suivante :

http://127.0.0.1

Exemples de commande

Lancer le mode graphique :

./versiondynamique -gr

Lancer le mode texte :

./versiondynamique -txt

Lancer l'interface web :

./versiondynamique

Structure du projet

versiondynamique.c : Fichier principal contenant la logique du programme.

log.c : Module pour lire les logs en temps réel.

