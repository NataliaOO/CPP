#ifndef CALCULATOR_VIEW_H
#define CALCULATOR_VIEW_H

#include <QKeyEvent>
#include <QMainWindow>

#include "../controller/calculator_controller.h"
#include "credit_view.h"
#include "deposit_view.h"

namespace Ui {
class CalculatorView;
}

/**
 * @class CalculatorView
 * @brief Main window class for the calculator application, handles user interface interactions.
 */
class CalculatorView : public QMainWindow {
  Q_OBJECT

 public:
  /**
   * @brief Constructs a CalculatorView object.
   * @param parent The parent widget (default is nullptr).
   */
  explicit CalculatorView(QWidget *parent = nullptr);

  /**
   * @brief Destructs the CalculatorView object.
   */
  ~CalculatorView();

 private slots:
  /**
   * @brief Initializes the buttons and their connections.
   */
  void InitButtons();

  /**
   * @brief Adds a token to the current expression.
   */
  void addToken();

  /**
   * @brief Calculates and displays the result of the current expression.
   */
  void getResult();

  /**
   * @brief Generates and displays a graph based on the current expression.
   */
  void getGraph();

  /**
   * @brief Clears the input field.
   */
  void cleanInput();

  /**
   * @brief Handles key press events.
   * @param event The QKeyEvent object containing event details.
   */
  void keyPressEvent(QKeyEvent *event);

  /**
   * @brief Slot called when the Pi button is clicked.
   */
  void onPushButtonPiClicked();

  /**
   * @brief Draws a graph based on the provided input string.
   * @param inputString The input expression used to generate the graph.
   */
  void drawGraph(std::string &inputString);

  /**
   * @brief Opens the deposit view window.
   */
  void openDepositView();

  /**
   * @brief Opens the credit view window.
   */
  void openCreditView();

 private:
  Ui::CalculatorView *ui;
  s21::CalculatorController *calc_;
  double X_;
  double step_;
  QVector<double> x_;
  QVector<double> y_; 
};

#endif  // CALCULATOR_VIEW_H
