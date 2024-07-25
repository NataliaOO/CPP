/**
 * @file credit_model.h
 */

#ifndef CREDIT_MODEL_H
#define CREDIT_MODEL_H

#include <cmath>
#include <vector>

namespace s21 {

/**
 * @class CreditCalculatorModel
 * @brief Class for performing credit calculations.
 */
class CreditCalculatorModel {
 private:
  struct CreditData;
  struct CreditReport;

 public:
  CreditCalculatorModel() = default;

  /**
   * @brief Construct a new CreditCalculatorModel object with given credit data.
   * @param data Credit data for calculations
   */
  CreditCalculatorModel(CreditData data);

  ~CreditCalculatorModel() = default;

  /**
   * @brief Perform the credit calculation.
   */
  void creditCalculator();

  /**
   * @brief Check if the end of the month is reached.
   * @return true if the end of the month is reached, false otherwise
   */
  bool isEndOfMonths();

  /**
   * @brief Get the report of the credit calculation.
   * @return A vector containing the credit report details
   */
  std::vector<double> getReport();

 private:
   /**
   * @struct CreditData
   * @brief Structure for storing credit input data.
   * @param sum Total credit amount
   * @param month Duration of credit in months
   * @param creditRate Annual credit interest rate
   * @param isDiff Flag indicating if the credit is differentiated
   */
  struct CreditData {
    double sum;  
    int month;
    double creditRate;
    int isDiff;
  };

  /**
   * @struct CreditReport
   * @brief Structure for storing credit calculation results.
   * @param monthPayment Monthly payment amount
   * @param overPayment Total overpayment
   * @param totalPayment Total payment including overpayment
   * @param months Number of months for the credit
   */
  struct CreditReport {
    double monthPayment;
    double overPayment;
    double totalPayment;
    int months;
  };

  CreditData crData_;
  CreditReport crReport_;
};

}  // namespace s21

#endif  // CREDIT_MODEL_H
