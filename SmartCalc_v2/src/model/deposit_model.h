/**
 * @file credit_model.h
 */
#ifndef DEPOSIT_MODEL_H
#define DEPOSIT_MODEL_H

#include <cmath>
#include <vector>

namespace s21 {

/**
 * @class DepositCalculatorModel
 * @brief Class for performing deposit calculations.
 */
class DepositCalculatorModel {
 private:
  /**
   * @struct DepositData
   * @brief Structure for storing deposit input data.
   * @param depositSum Initial deposit amount
   * @param fullPeriod Duration of the deposit in periods
   * @param percentageRate Annual interest rate
   * @param taxRate Tax rate on interest income
   * @param keyRate Key rate for calculations
   * @param capitalization Flag indicating if interest is capitalized
   */
  struct DepositData {
    double depositSum;
    int fullPeriod;
    double percentageRate;
    double taxRate;
    double keyRate;
    int capitalization;
  };

  /**
   * @struct DepositReport
   * @brief Structure for storing deposit calculation results.
   * @param period Current period of the deposit
   * @param tax Tax amount for the current period
   * @param accruedCash Accrued interest for the current period
   * @param cashFlow Cash flow for the current period
   * @param balance Balance of the deposit after the current period
   */
  struct DepositReport {
    double period;
    double tax;
    double accruedCash;
    double cashFlow;
    double balance;
  };

  DepositData dtData_;
  DepositReport dtReport_;

 public:
  DepositCalculatorModel() = default;

  /**
   * @brief Construct a new DepositCalculatorModel object with given deposit data.
   * @param data Deposit data for calculations
   */
  DepositCalculatorModel(DepositData data);

  ~DepositCalculatorModel() = default;

  /**
   * @brief Check if the end of the period is reached.
   * @return true if the end of the period is reached, false otherwise
   */
  bool isEndOfPeriod();

  /**
   * @brief Get the report of the deposit calculation.
   * @return A vector containing the deposit report details
   */
  std::vector<double> getReport();

  /**
   * @brief Calculate the tax for the current period.
   * @return The tax amount for the current period
   */
  double calcTax();

  /**
   * @brief Perform the deposit calculation.
   */
  void depositCalculator();
};

}  // namespace s21

#endif  // DEPOSIT_MODEL_H