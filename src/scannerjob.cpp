/*
Dwarf Therapist
Copyright (c) 2009 Trey Stout (chmod)

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/
#include "scannerjob.h"
#include "dfinstance.h"

ScannerJob::ScannerJob(SCANNER_JOB_TYPE job_type)
    : m_job_type(job_type)
{
    m_ok = get_DFInstance();
}
ScannerJob::~ScannerJob() {
    if (m_df)
        delete m_df;
    m_df = 0;
}

SCANNER_JOB_TYPE ScannerJob::job_type() {
    return m_job_type;
}

DFInstance *ScannerJob::df() {
    return m_df;
}

QString ScannerJob::m_layout_override_checksum("");

bool ScannerJob::get_DFInstance() {
    m_df = DFInstance::newInstance();
    bool result = m_df->find_running_copy(true);

    if(!m_layout_override_checksum.isEmpty()) {
        m_df->set_memory_layout(m_df->get_memory_layout(m_layout_override_checksum, false));
    }

    return result;
}
