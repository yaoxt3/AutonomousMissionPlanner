#ifndef DETAILSVIEW_H
#define DETAILSVIEW_H

#include <QWidget>

class AutonomousVehicleProject;
class BackgroundDetails;
class WaypointDetails;
class TrackLineDetails;
class SurveyPatternDetails;
class PlatformDetails;
class ROSNodeDetails;

class DetailsView : public QWidget
{
    Q_OBJECT
public:
    explicit DetailsView(QWidget *parent = 0);

    void setProject(AutonomousVehicleProject *project);

    QSize sizeHint() const override;

signals:

public slots:
    void onCurrentItemChanged(const QModelIndex  &current, const QModelIndex &previous);

private:
    AutonomousVehicleProject *m_project;

    QWidget * currentWidget;

    BackgroundDetails * backgroundDetails;
    WaypointDetails * waypointDetails;
    TrackLineDetails * trackLineDetails;
    SurveyPatternDetails * surveyPatternDetails;
    PlatformDetails * platformDetails;
    ROSNodeDetails * rosNodeDetails;

    void setCurrentWidget(QWidget *widget);
};

#endif // DETAILSVIEW_H
