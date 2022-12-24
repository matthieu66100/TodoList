#include <QApplication>
#include <QtWidgets>

int main(int argc, char* argv[])
{
  QApplication app(argc, argv);

  // Création de la fenêtre principale
  QWidget* window = new QWidget;
  window->setWindowTitle("Todo List");

  // Création du layout vertical
  QVBoxLayout* layout = new QVBoxLayout;

  // Création de la liste de tâches
  QListWidget* taskList = new QListWidget;

  // Création du champ de saisie de la tâche
  QLineEdit* taskEdit = new QLineEdit;

  // Création du bouton d'ajout de tâche
  QPushButton* addButton = new QPushButton("Ajouter");

  // Connexion du signal de clic sur le bouton d'ajout au slot d'ajout de tâche
  QObject::connect(addButton, &QPushButton::clicked, [&]()
  {
    QString task = taskEdit->text();
    if (!task.isEmpty())
    {
      taskList->addItem(task);
      taskEdit->clear();
    }
  });

  // Création du bouton de suppression de tâche
  QPushButton* deleteButton = new QPushButton("Supprimer");

  // Connexion du signal de clic sur le bouton de suppression au slot de suppression de tâche
  QObject::connect(deleteButton, &QPushButton::clicked, [&]()
  {
    // Récupération de l'élément sélectionné dans la liste de tâches
    QListWidgetItem* selectedItem = taskList->currentItem();
    if (selectedItem)
    {
      // Suppression de l'élément sélectionné
      delete selectedItem;
    }
  });

  // Ajout de la liste de tâches, du champ de saisie et des boutons d'ajout et de suppression au layout
  layout->addWidget(taskList);
  layout->addWidget(taskEdit);
  layout->addWidget(addButton);
  layout->addWidget(deleteButton);

  // Configuration de la fenêtre principale
  window->setLayout(layout);
  window->show();

  return app.exec();
}
