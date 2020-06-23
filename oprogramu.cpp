#include "oprogramu.h"

OProgramu::OProgramu(const QString& verzija)
{
    ui.setupUi(this);
    ui.label_info->setText("Proračun\n\nIzdelal Nejc Sedovnik\nJunij 2020\nVerzija " + verzija);
    ui.label_info->setAlignment(Qt::AlignCenter);
}

OProgramu::~OProgramu()
{

}
