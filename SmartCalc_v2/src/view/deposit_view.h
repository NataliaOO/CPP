#ifndef DEPOSIT_VIEW_H
#define DEPOSIT_VIEW_H

#include <QStandardItemModel>
#include <QWidget>

#include "../controller/deposit_controller.h"

namespace Ui {
class DepositView;
}

/**
 * @class DepositView
 * @brief Widget for the deposit calculator interface, handling user interactions for deposit calculations.
 */
class DepositView : public QWidget {
  Q_OBJECT

 public:
  /**
   * @brief Constructs a DepositView object.
   * @param parent The parent widget (default is nullptr).
   */
  explicit DepositView(QWidget *parent = nullptr);

  /**
   * @brief Destructs the DepositView object.
   */
  ~DepositView();

 private slots:
  /**
   * @brief Slot called when the "Get Deposit" button is clicked.
   */
  void on_getDepositButton_clicked();

 private:
  Ui::DepositView *ui;
  QStandardItemModel *model;
  s21::DepositCalculatorController *deposit_;
};

#endif  // DEPOSIT_VIEW_H