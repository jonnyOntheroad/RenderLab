#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_RenderLab.h"

#include <CppUtil/Qt/PaintImgOpCreator.h>
#include <CppUtil/Basic/Ptr.h>

namespace CppUtil {
	namespace Basic {
		class Operation;
	}
	namespace Engine {
		class Scene;
		class Viewer;
	}
}

namespace Ui {
	class Hierarchy;
	class Attribute;
}

class RenderLab : public QMainWindow
{
	Q_OBJECT

public:
	RenderLab(QWidget *parent = Q_NULLPTR);

public:
	CppUtil::Basic::Ptr<CppUtil::Engine::Scene> GetScene()const { return scene; }

private slots:
	void on_btn_RenderStart_clicked();
	void on_btn_RenderStop_clicked();
	void on_btn_SaveRasterImg_clicked();
	void on_btn_SaveRayTracerImg_clicked();

	void on_tree_Hierarchy_itemClicked(QTreeWidgetItem *item, int column);

	void UI_Op(CppUtil::Basic::Ptr<CppUtil::Basic::Operation> op);

private:
	Ui::RenderLabClass ui;
	CppUtil::Basic::Ptr<CppUtil::Qt::PaintImgOpCreator::PaintImgOp> paintImgOp;
	CppUtil::Basic::Ptr<CppUtil::Engine::Scene> scene;
	CppUtil::Basic::Ptr<CppUtil::Engine::Viewer> viewer;
	CppUtil::Basic::Ptr<Ui::Hierarchy> hierarchy;
	CppUtil::Basic::Ptr<Ui::Attribute> attr;
};
