# Projet d'initiation à C++ !

L'objectif de ce projet est de créer un jeu Pokemon minimaliste en C++.

### *Fonctionnement du jeu*

#### *Lancement*

Lors de l'exécution du projet, on entre dans un état *"StateAttente"* qui constitue le **menu d'accueil** du jeu.
L'utilisateur peut alors entrer le pseudonyme de son personnage et lancer le jeu avec la touche *"Entrée"*.

Le lancement du jeu nous fait passer dans un état *"StateInit"* qui initialise le joueur avec le pseudonyme choisi et **une Pokeball** (système de stockage des Pokemons capturés) **vide**.

#### *Capture du premier Pokemon*

Puis le gameplay commence avec le passage dans l'état *"StateExplorationSansDanger"*.
Dans cet état, le joueur peut **seulement rencontrer des pokemons sauvages**.
A chaque rencontre, on lui affiche les statistiques du Pokemon en question, et on lui laisse le choix d'essayer de le capturer ou non.
En cas de réponse positive, le joueur a **50% de chances de capturer le Pokemon**, l'ajoutant dans sa Pokeball.
Sinon, **le Pokemon sauvage s'enfuit**.

Cet état a pour but de permettre au joueur de **capturer au moins un Pokemon** avant qu'il soit possiblement confronté à un **dresseur**.
C'est pourquoi à l'issue de chaque rencontre, on vérifie s'il possède au moins un Pokemon.
Dans ce cas, on bascule dans l'état *"StateExploration"*.

#### *Boucle principale de gameplay*

Dans cet état, à chaque évènement, le joueur a **80%** de chances de rencontrer un **Pokemon sauvage** et **20%** de rencontrer un **dresseur**.
La confrontation avec un Pokemon sauvage se passe de la même manière que lors de l'état précédent.

Lorsque le joueur rencontre un dresseur, il peut choisir **entre 1 et 6 Pokemons** parmi ceux qu'il a capturé.
**Chaque Pokemon ne peut servir que dans un seul combat**, même si le combat est gagné.
L'équipe du dresseur adverse, constituée aléatoirement, comporte autant de Pokemons que celle du joueur.

Le combat commence par le tour du joueur.
Il peut choisir **d'attaquer** ou de **changer de Pokemon**.
L'attaque **inflige des dégâts** si l'attaque du Pokemon attaquant est strictement supérieure à la défense du Pokemon attaqué, sinon **elle échoue**.
Lorsqu'une attaque échoue, le Pokemon attaquant s'inflige **20 points de dégâts**.
Cela permet d'éviter un potentiel SoftLock si deux Pokemons défensifs s'affrontent.
Le nombre de points de vie retirés par une attaque correspond à **la différence entre les deux statistiques**.

Si le joueur choisit de remplacer son Pokemon, il envoie automatiquement le **Pokemon suivant dans sa PokemonParty**.
L'ordre dans lequel les Pokemons sont choisis a donc de l'importance.

Lorsqu'un Pokemon tombe KO (lorsque ses points de vie atteignent 0), il est **automatiquement remplacé par le Pokemon suivant** dans l'équipe.
S'il s'agissait du dernier Pokemon, le joueur adverse **gagne le combat**.

### *Conditions de victoire / défaite*

La partie prend fin lorsque le joueur **perd un combat** contre un dresseur.
On affiche alors son score final sous la forme du **nombre de Pokemons adverses qu'il a mis K.O.**.
Remporter un combat avec **plusieurs Pokemons dans son équipe** rapporte donc **davantage de points**.
Il n'y a pas de condition de victoire puisque le jeu est **potentiellement infini**.

