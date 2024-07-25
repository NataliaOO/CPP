#ifndef DEPOSIT_CONTROLLER_H
#define DEPOSIT_CONTROLLER_H

#include <vector>

#include "../model/deposit_model.h"

namespace s21 {

/**
 * @class DepositCalculatorController
 * @brief Controller class to interface with the DepositCalculatorModel.
 */
class DepositCalculatorController {
 public:
  /**
   * @brief Default constructor for DepositCalculatorController.
   */
  DepositCalculatorController() = default;

  /**
   * @brief Constructor for DepositCalculatorController that initializes the model.
   * @param m Pointer to a DepositCalculatorModel object.
   */
  DepositCalculatorController(DepositCalculatorModel* m);

  /**
   * @brief Default destructor for DepositCalculatorController.
   */
  ~DepositCalculatorController() = default;

  /**
   * @brief Runs the next iteration of the deposit calculation.
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
  DepositCalculatorModel* model_;
};

}  // namespace s21

#endif