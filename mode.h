void modeSelect()
{
    switch (mode)
    {
    case 0:
        setColor(240, 162, 11);
        break;
    case 1:
        setColor(233, 169, 232);
        break;
    case 2:
        setColor(19, 232, 174);
        break;
    case 3:
        setColor(242, 59, 76);
        break;
    case 4:
        setColor(73, 185, 249);
        break;
    case 5:
        setColor(137, 137, 137);
        break;
    case 6:
        setColor(230, 214, 23);
        break;
    case 7:
        setColor(174, 88, 235);
        break;
    case 8:
        setColor(251, 117, 228);
        break;
    case 9:
        rgbFade();
        break;
    case 10:
        rgbCycle();
        break;
    case 11:
        flash();
        break;
    case 12:
        btlControl();
        break;
    default:
        mode = 0;
        modeSelect();
    }
}
