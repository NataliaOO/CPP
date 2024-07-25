#ifndef CREDIT_VIEW_H
#define CREDIT_VIEW_H

#include <QStandardItemModel>
#include <QWidget>

#include "../controller/credit_controller.h"

namespace Ui {
class CreditView;
}

/**
 * @class CreditView
 * @brief Widget for the credit calculator interface, managing user interactions for credit calculations.
 */
class CreditView : public QWidget {
  Q_OBJECT

 public:
  /**
   * @brief Constructs a CreditView object.
   * @param parent The parent widget (default is nullptr).
   */
  explicit CreditView(QWidget *parent = nullptr);

  /**
   * @brief Destructs the CreditView object.
   */
  ~CreditView();

 private slots:
  /**
   * @brief Slot called when the "Get Credit" button is clicked.
   */
  void on_getCreditButton_clicked();

 private:
  Ui::CreditView *ui;
  QStandardItemModel *model;
  s21::CreditCalculatorController *credit_;
};

#endif  // CREDIT_VIEW_H