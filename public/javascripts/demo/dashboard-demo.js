$(function() {

    Morris.Area({
        element: 'morris-area-chart',
        data: [{
            period: '2016-01',
            ECU: 2647
        }, {
            period: '2016-02',
            ECU: 2441
        }, {
            period: '2016-03',
            ECU: 2501
        }, {
            period: '2016-04',
            ECU: 1000
        }, {
            period: '2016-05',
            ECU: 2293
        }, {
            period: '2016-06',
            ECU: 1881
        }, {
            period: '2016-07',
            ECU: 1588
        }, {
            period: '2016-08',
            ECU: 5175
        }, {
            period: '2016-09',
            ECU: 2028
        }, {
            period: '2016-10',
            ECU: 1791
        },
        {
            period: '2016-11',
            ECU: 1874
        },
        {
            period: '2016-12',
            ECU: 1520
        }],
        xkey: ['period'],
        ykeys: ['ECU'],
        labels: ['Nb ECU'],
        pointSize: 2,
        hideHover: 'auto',
        resize: true
    });


});
