# 2.2.1 - Speech Analysis #



Dans l'idée de pouvoir tester correctement et étape par étape les différents composants de l'IA, le choix fut fait de réaliser un logiciel graphique qui permettrait d’accéder à l'ensemble des informations dont on dispose au cours de l'analyse des phrases ainsi que d'un arbre visuel représentant le déroulement du dialogue et ses étapes.

Dans sa phase première on a décomposé les phrases en séries de boutons comme ceci :

//IMAGE : SpeechAnalysis.jpg

Ainsi nous avons su définir précisément ce que nous avions en entrée. Une fois chaque mot identifié, il est recherché dans la base de données pour des informations utiles :
  * type
  * genre
  * brève description
  * synonymes
  * si c'est un verbe, sa conjugaison à tous les temps

Un code couleur pour les mots permet de distinguer les mots inconnus :

  * rouge = inconnu
  * vert = connu
  * jaune = en recherche

Une fois les mots identifiés, il est possible d'analyser la phrase.

Pour la phase d'analyse nous avons choisi de nous réferrer à un système de Règles écrites dans un script que nous avons mis en place.
Le script est un pseudo-langage interprété à la volée et executé à chaque analyse de phrase. Un script permet de spécifier un comportement ou un élement de réponse de l'IA.
Par exemple il est possible d'executer des scripts externes de contrôle d'applications (comme firefox ou thunderbird). Ou bien spécifier l'évolution des branches de l'arbre de dialogue.



Bien entendu la mise en place d'un tel système d'analyse nécessite une base de données solide.

# 2.2.2 - La base de données #

Dès le début du développement de l'IA il était devenu clair que nous avions besoin d'un support de données qui n'était pas accessible en tant que tel, il était alors nécessaire de le créer.
Nous avons donc réalisé une série de programmes console dont le but était de piocher dans les bases de données ###### A REMPLIR ##### afin d'obtenir une base cohérente et contenant toutes les données dont nous avions besoin.

Pour recueillir toutes ces données les éléments suivants ont été mis en œuvre :
  * système de requête HTML pour les bases de données en ligne
  * parseur HTML, XML