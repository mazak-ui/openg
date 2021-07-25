#pragma once

#include <memory>

#include <QStackedLayout>

#include "selfdrive/common/util.h"
#include "selfdrive/ui/qt/widgets/cameraview.h"

class DriverViewScene : public QWidget {
  Q_OBJECT

public:
  explicit DriverViewScene(QWidget *parent);

signals:
  void done();

public slots:
  void frameUpdated();

protected:
  void showEvent(QShowEvent *event) override;
  void hideEvent(QHideEvent *event) override;
  void paintEvent(QPaintEvent *event) override;
  void mousePressEvent(QMouseEvent* e) override;

private:
  Params params;
  SubMaster sm;
  QImage face;
  bool is_rhd = false;
  bool frame_updated = false;
  const Rect d_rec_btn = {1745, 905, 140, 140};
  bool infill;
};

class DriverViewWindow : public QWidget {
  Q_OBJECT

public:
  explicit DriverViewWindow(QWidget *parent);

private:
  CameraViewWidget *cameraView;
  DriverViewScene *scene;
  QStackedLayout *layout;
};
