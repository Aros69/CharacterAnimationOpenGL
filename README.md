# Mif37CharAnim TP 

Étudiant : Robin DONNAY, 11510329  
Mail : robin.donnay@etu.univ-lyon1.fr  

## Compilation et éxecution

- Pour compiler (sous linux avec le shell) : `premake4 --file=master_CharAnim.lua gmake && make -f master_CharAnim.make` 
- Pour compiler (avec Cmake), utilisez le "CmakeLists.txt" à la racine du projet   
- Pour lancer le programme (sous linux avec le shell) : `bin/master_CharAnim` (si compilation "classique") ou `./gki2light_master_CharAnim` (si compilation avec Cmake)

## Commandes de jeux

- 'n' permet de faire avancer le temps du grand squelette a gauche pour visionner son animation
- 'b' permet de faire reculer le temps du squelette (attention à ne pas descendre en dessous de 0 sinon c'est bizarre)
- 'z', 'q', 's' et 'd' permettent de faire bouger le bonhomme au centre ainsi que la sphere/cube derriere lui
- 'x' permet de donner un coup de pied et afficher des informations sur la sphere/cube
- 'left shift' permet de s'accroupir et de se deplacer plus doucement (si combine avec zqsd)
- '1', '2', '3' permettent de danser si vous ne bouger pas
- 'espace' permet de rentrer dans l'état fumeur (si vous ne bougez pas). Ce dernier vous empeche d'avancer. Appuyez sur 'a' pour fumer (autant de fois que souhaite), appuyez sur 'e' pour arreter et recommencer a bouger.  

## Travail proposé

- Visionnage d'une animation (cf : "src/master_CharAnim/Skeleton.cpp")  
- Controle d'une sphère/cube... (cf : "src/master_CharAnim/CubeController.cpp")  
- Animation et controle d'un personnage  (cf : "src/master_CharAnim/CharacterController.cpp")  
- Véritable State Machine permettant l'ajout rapide et simple d'animation à un personnage (cf : "src/master_CharAnim/Animations/") 
- (EN COURS) Création d'un graphe d'animation 
