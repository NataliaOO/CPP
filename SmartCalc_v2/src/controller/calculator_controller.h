#ifndef CALCULATOR_CONTROLLER_H
#define CALCULATOR_CONTROLLER_H

#include "../model/calculator_model.h"

namespace s21 {

/**
 * @class CalculatorController
 * @brief Controller class to interface with the CalculatorModel.
 */
class CalculatorController {
 public:
  /**
   * @brief Default constructor for CalculatorController.
   */
  CalculatorController() = default;

  /**
   * @brief Constructor for CalculatorController that initializes the model.
   * @param m Pointer to a CalculatorModel object.
   */
  CalculatorController(CalculatorModel* m);

  /**
   * @brief Default destructor for CalculatorController.
   */
  ~CalculatorController() = default;

  /**
   * @brief Starts the calculator with the given expression and optional value for x.
   * @param exp Mathematical expression to be evaluated.
   * @param x Value of the variable x in the expression (default is 0).
   * @return Error status of the calculation.
   */
  int startCalculator(std::string exp, double x = 0);

  /**
   * @brief Gets the error status from the last calculation.
   * @return Error status code.
   */
  int getErrorStatus();

  /**
   * @brief Gets the error message from the last calculation.
   * @return Error message string.
   */
  std::string getErrorMessage();

  /**
   * @brief Gets the result of the last calculation.
   * @return Result of the calculation.
   */
  double getResult();

 private:
  CalculatorModel* model_;
  int errorStatus_;
};

}  // namespace s21

#endif