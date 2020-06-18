#include "vnosobveznosti.h"

VnosObveznosti::VnosObveznosti() :
    ui(new Ui::VnosObveznosti)
{
    ui->setupUi(this);
}

VnosObveznosti::~VnosObveznosti()
{
    delete ui;
}
