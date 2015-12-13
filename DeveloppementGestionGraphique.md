# 2.4.1 - Créer un visage pour Sarah #

Sarah est sensée posséder un visage en 3d s'affichant à l'écran lorsqu'elle parle, ce visage est en fait un modèle 3D possédant des animations et affiché par le moteur OGRE 3D dans la fenêtre de l'application finale.

Pour réaliser cela je vais passer par 3 étapes :

  1. Modélisation
  1. "Skin" du modèle
  1. Animation



## 2.4.1.1 Modélisation ##

//IMAGE Modele3D.jpg

J'ai trouvé un modèle de femme sur internet et j'ai découpé son visage affin d'obtenir ça. Il s'agit d'un modèle de 1294 points.
Dans le processus l'idée m'est venue de faire non pas un visage mais une sorte de masque dramatique pour que le graphisme final colle avec la voix synthétique sans choquer l'utilisateur.

## 2.4.1.2 "Skin" du modèle ##

//IMAGE sarah\_proj.jpg

Il s'agit d'un processus permettant, en plaçant une sorte de squelette à l’intérieur du modèle de créer un mécanisme de déformation de la "skin" ou "peau". En effet le modèle entier est alors considéré comme de la peau. Une fois le squelette placé et la peau bien calibrée afin que sa déformation soit harmonieuse avec les positions des "os" Sarah devrait pouvoir sourire, rire, être triste, s'étonner, etc...encore s'agit t-il de créer ces animations par la suite!

N'ayant pas énormément de savoir faire en modélisation et skinning, j'ai passé beaucoup de temps sur la réalisation du squelette, l'enjeu consiste à rester le plus près possible de la morphologie naturelle du visage en prenant en compte la rigidité des os.

//IMAGE sarah\_proj\_helpers.jpg

Une fois le squelette établi, il faut mettre en place des "aides" d'animation appelés Helpers. Ce sont en fait des éléments seulement visibles dans le logiciel d'édition et permettant de modifier les positions des os dans le squelette facilement, ils n'ont aucun impact sur la sauvegarde d'une animation et son traitement dans le moteur graphique lors du rendu en temps réel.