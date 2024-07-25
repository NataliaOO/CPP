#ifndef CREDIT_CONTROLLER_H
#define CREDIT_CONTROLLER_H

#include <vector>

#include "../model/credit_model.h"

namespace s21 {

/**
 * @class CreditCalculatorController
 * @brief Controller class to interface with the CreditCalculatorModel.
 */
class CreditCalculatorController {
 public:
  /**
   * @brief Default constructor for CreditCalculatorController.
   */
  CreditCalculatorController() = default;

  /**
   * @brief Constructor for CreditCalculatorController that initializes the model.
   * @param m Pointer to a CreditCalculatorModel object.
   */
  CreditCalculatorController(CreditCalculatorModel* m);

  /**
   * @brief Default destructor for CreditCalculatorController.
   */
  ~CreditCalculatorController() = default;

  /**
   * @brief Runs the next iteration of the credit calculation.
   */
  void runNextIteration();

  /**
   * @brief Checks if the current iteration is the last one.
   * @return True if the current iteration is the last one, false otherwise.
   */
  bool isEndOfIteration();

  /**
   * @brief Gets the report of the current iteration.
   * @return A vector containing the report data of the current iteration.
   */
  std::vector<double> getIterationReport();

 private:
  CreditCalculatorModel* model_;
};

}  // namespace s21

#endif