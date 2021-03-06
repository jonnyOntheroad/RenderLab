#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_RenderLab.h"

#include <CppUtil/Qt/PaintImgOpCreator.h>
#include <CppUtil/Basic/Ptr.h>

namespace CppUtil {
	namespace Basic {
		class Op;
	}
	namespace Engine {
		class Scene;
		class Viewer;
		class RTX_Renderer;
		class PathTracer;
	}
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
	void on_btn_Denoise_clicked();

	void UI_Op(CppUtil::Basic::Ptr<CppUtil::Basic::Op> op);

private:
	void InitSetting();

private:
	Ui::RenderLabClass ui;
	CppUtil::Basic::Ptr<CppUtil::QT::PaintImgOpCreator::PaintImgOp> paintImgOp;
	CppUtil::Basic::Ptr<CppUtil::Engine::Scene> scene;
	CppUtil::Basic::Ptr<CppUtil::Engine::Viewer> viewer;
	CppUtil::Basic::Ptr<CppUtil::Engine::RTX_Renderer> rtxRenderer;

private:
	// setting
	int maxDepth;
	int maxLoop;
};
